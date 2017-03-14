package xyz.elmot.oscill;

import purejavacomm.*;

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
                    oscilloscope.enableReceiveTimeout(500);
                } catch (UnsupportedCommOperationException e) {
                    System.err.println("Timeout not supported");
                }
                try (InputStream inputStream = oscilloscope.getInputStream();
                     OutputStream cmdStream = oscilloscope.getOutputStream()) {

                    sendStatus("Connected", true);
                    byteCounter.set(0);
                    while (running) {
                        for (String s; (s = cmdQueue.poll()) != null; ) {
                            cmdStream.write(s.getBytes(StandardCharsets.US_ASCII));
                            cmdStream.write(CRLF);
                            waitChar(inputStream, 'O');
                            waitChar(inputStream, 'K');
                            waitChar(inputStream, (char) 10);
                            waitChar(inputStream, (char) 13);
                            queue.clear();
                        }
                        waitForCommand();
                        cmdStream.write("\nFRAME\n".getBytes());
                        int head = read16(inputStream);
                        if ((head & 0x8000) == 0) {
                            sendStatus("Broken header", true);
                            break;
                        }
                        readResponseData(inputStream, head);
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

    private void waitChar(InputStream inputStream, char ch) throws IOException {
        int b = inputStream.read();
        if (b != ch) {
            throw new IOException(
                    String.format("Wrong reply: expected 0x%02X, receibed 0x%02X", (int) ch, b));
        }
    }

    protected abstract void readResponseData(InputStream inputStream, int head) throws IOException;

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
        private static final int N_CHANNELS = 1;/*todo*/

        @SuppressWarnings("WeakerAccess")
        public Frame(String portName, BiConsumer<String, Boolean> portStatusConsumer, int queueDepth, int delay) {
            super(portName, portStatusConsumer, queueDepth, delay);
        }

        protected void readResponseData(InputStream inputStream, int head) throws IOException {
            int len = (head & 0xfff) / N_CHANNELS;
            short data[] = new short[len];
            for (int i = 0; i < data.length; i++) {
                data[i] = read16(inputStream);
            }
            FrameData.TYPE type = Math.random() < 0.1 ? FrameData.TYPE.NORMAL : FrameData.TYPE.TRIGGERED;
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

        protected void readResponseData(InputStream inputStream, int head) throws IOException {
            int len = (head & 0xfff);
            byte data[] = new byte[2 + 2 * len];
            data[0] = (byte) head;
            data[1] = (byte) (head >> 8);
            for (int i = 2; i < data.length; i++) {
                data[i] = (byte) inputStream.read();
            }

            try {
                queue.put(data);
            } catch (InterruptedException ignored) {
            }
        }
    }
}
