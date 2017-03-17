package xyz.elmot.oscill;

import purejavacomm.*;
import xyz.elmot.oscill.FrameData.TYPE;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.StandardCharsets;
import java.util.Collections;
import java.util.Objects;
import java.util.Queue;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ConcurrentLinkedDeque;
import java.util.concurrent.atomic.AtomicLong;
import java.util.function.BiConsumer;

/**
 * (c) elmot on 2.3.2017.
 */
public abstract class CommThread<T> extends Thread {
    private final String portName;
    private final BiConsumer<String, Boolean> portStatusConsumer;
    private final int delay;
    private volatile boolean running = true;
    @SuppressWarnings("WeakerAccess")
    protected final BlockingQueue<T> queue;
    protected final Queue<String> cmdQueue;
    private String status;
    private final AtomicLong byteCounter = new AtomicLong(0);
    private boolean connected;
    public static final byte[] CRLF = new byte[]{10, 13};

    @SuppressWarnings("WeakerAccess")
    public CommThread(String portName, BiConsumer<String, Boolean> portStatusConsumer, int queueDepth, int delay) {
        setDaemon(true);
        this.portName = portName;
        this.portStatusConsumer = portStatusConsumer;
        sendStatus("Not started", false);
        queue = new ArrayBlockingQueue<>(queueDepth);
        cmdQueue = new ConcurrentLinkedDeque<>();
        this.delay = delay;
    }

    private void sendStatus(String newStatus, boolean connected) {
        if ((!Objects.equals(newStatus, this.status)
                || this.connected != connected)) {
            if (portStatusConsumer != null) {
                portStatusConsumer.accept(newStatus, connected);
            }
            this.connected = connected;
            this.status = newStatus;
            System.err.println((connected ? "CONNECTED: " : "DISCONNECTED: ") + status);
        }
    }

    @SuppressWarnings("WeakerAccess")
    public void giveUp() {
        running = false;
        interrupt();
        while (this.isAlive()) ;
    }

    @Override
    public void run() {
        SerialPort oscilloscope;
        CommPortIdentifier portIdentifier;

        while (running) {
            for (portIdentifier = null; running & portIdentifier == null; ) {
                try {
                    portIdentifier = CommPortIdentifier.getPortIdentifier(portName);
                } catch (NoSuchPortException e) {
                    sendStatus("Port is not available", false);
                    sleepMe(250);
                }
            }
            for (oscilloscope = null; running && oscilloscope == null && portIdentifier != null; ) {
                try {
                    oscilloscope = (SerialPort) portIdentifier.open("Oscilloscope", 250);
                } catch (PortInUseException e) {
                    sendStatus("Port is in use", false);
                }
            }
            if (oscilloscope != null) {
                try {
                    oscilloscope.enableReceiveTimeout(200);
                } catch (UnsupportedCommOperationException e) {
                    System.err.println("Timeout not supported");
                }
                try (InputStream inputStream = oscilloscope.getInputStream();
                     OutputStream cmdStream = oscilloscope.getOutputStream()) {
                    /* ***  Skip garbage if any *** */
                    try {
                        //noinspection StatementWithEmptyBody
                        while (inputStream.read() >= 0) ;
                    } catch (IOException ignored) {
                    }

                    sendStatus("Connected", true);
                    byteCounter.set(0);
                    while (running) {
                        for (String s; (s = cmdQueue.poll()) != null; ) {
                            cmdStream.write(s.getBytes(StandardCharsets.US_ASCII));
                            cmdStream.write(CRLF);
                            cmdStream.flush();
                            sleepMe(50);
                            //todo ack for the command
                            queue.clear();
                        }
                        waitForCommand();
                        cmdStream.write("\nFRAME\n".getBytes());
                        cmdStream.flush();
                        int length = read16(inputStream);
                        if ((length & 0x8000) == 0 || (length&0x7fff) < 600) {
                            sendStatus("Broken header", true);
                            break;
                        }
                        readResponseData(inputStream, length);
                    }
                } catch (IOException e) {
                    sendStatus("Port exchange error:" + e.getMessage(), false);
                } finally {
                    if (connected) {
                        sendStatus("Closed", false);
                    }
                    oscilloscope.close();
                }
            }
        }
    }

    protected abstract void readResponseData(InputStream inputStream, int lenBytes) throws IOException;

    @SuppressWarnings("WeakerAccess")
    protected void waitForCommand() {
        sleepMe(delay);
    }

    @SuppressWarnings("SameParameterValue")
    private void sleepMe(long millis) {
        if (millis > 0)
            try {
                Thread.sleep(millis);
            } catch (InterruptedException ignored) {
            }
    }


    short read16(InputStream in) throws IOException {
        int val = in.read();
        if (val < 0) throw new IOException("unexpected EOF at " + byteCounter);
        byteCounter.incrementAndGet();
        int c = in.read();
        if (c < 0) throw new IOException("unexpected EOF at " + byteCounter);
        byteCounter.incrementAndGet();
        val |= c * 256;
        return (short) val;
    }

    @SuppressWarnings("unused")
    public boolean isRunning() {
        return running;
    }

    @SuppressWarnings("WeakerAccess")
    public BlockingQueue<T> getQueue() {
        return queue;
    }

    @SuppressWarnings("unused")
    public boolean isConnected() {
        return connected;
    }

    public void sendCommand(String cmd) {
        cmdQueue.add(cmd);
    }

    @SuppressWarnings("WeakerAccess")
    public static String[] ports() {
        return Collections.list(CommPortIdentifier.getPortIdentifiers()).stream()
                .filter(identifier -> identifier.getPortType() == CommPortIdentifier.PORT_SERIAL)
                .map(CommPortIdentifier::getName).toArray(String[]::new);

    }

    public static class Frame extends CommThread<FrameData> {
        private static final int N_CHANNELS = 1;/*todo calculate*/

        @SuppressWarnings("WeakerAccess")
        public Frame(String portName, BiConsumer<String, Boolean> portStatusConsumer, int queueDepth, int delay) {
            super(portName, portStatusConsumer, queueDepth, delay);
        }

        protected void readResponseData(InputStream inputStream, int byteLen) throws IOException {
            int len = ((byteLen & 0x7fff)) / N_CHANNELS;
            short data[] = new short[len - 2];
            short head = read16(inputStream);
            for (int i = 0; i < data.length; i++) {
                data[i] = read16(inputStream);
            }
            TYPE type = (head & 0x4000) != 0 ? TYPE.TRIGGERED : TYPE.NORMAL;
            FrameData frameData = new FrameData(type, N_CHANNELS,
                    len, 12, new short[][]{data});
            try {
                queue.put(frameData);
            } catch (InterruptedException ignored) {
            }
        }
    }

    public static class Bytes extends CommThread<byte[]> {
        @SuppressWarnings("WeakerAccess")
        public Bytes(String portName, BiConsumer<String, Boolean> portStatusConsumer, int queueDepth, int delay) {
            super(portName, portStatusConsumer, queueDepth, delay);
        }

        protected void readResponseData(InputStream inputStream, int lenBytes) throws IOException {
            int len = (lenBytes & 0x7fff);
            byte data[] = new byte[len + 2];
            data[0] = (byte) (lenBytes >> 8);
            data[0] = (byte) (lenBytes & 0xff);
            for (int i = 2; i < data.length; i++) {
                int b = inputStream.read();
                if (b < 0)
                    throw new IOException("Data frame error");
                data[i] = (byte) b;
            }

            try {
                queue.put(data);
            } catch (InterruptedException ignored) {
            }
        }
    }
}
