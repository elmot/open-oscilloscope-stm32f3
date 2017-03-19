package xyz.elmot.oscill;

import purejavacomm.*;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.StandardCharsets;
import java.util.Collections;
import java.util.Objects;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.SynchronousQueue;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicLong;
import java.util.function.BiConsumer;

/**
 * (c) elmot on 2.3.2017.
 */
public class CommFacility extends Thread implements AutoCloseable {
    private volatile String portName;
    private BiConsumer<String, Boolean> portStatusConsumer;
    //private final int delay;
    private String status;
    private final AtomicLong byteCounter = new AtomicLong(0);
    private boolean connected = false;
    private static final byte[] CRLF = new byte[]{10, 13};
    private SerialPort oscilloscope;
    private CommPortIdentifier portIdentifier;
    private InputStream inputStream;
    private OutputStream cmdStream;

    private volatile boolean running = false;

    private SynchronousQueue<byte[]> cmdQueue = new SynchronousQueue<>();
    private SynchronousQueue<byte[]> cmdRespQueue = new SynchronousQueue<>();
    private ArrayBlockingQueue<byte[]> frames = new ArrayBlockingQueue<>(3);

    @SuppressWarnings("WeakerAccess")
    public CommFacility(BiConsumer<String, Boolean> portStatusConsumer) {
        super("Com port runner");
        this.portStatusConsumer = portStatusConsumer;
        sendStatus("Not started", false);
        setDaemon(true);
        start();
    }

    @SuppressWarnings("unused")
    public void giveUp() {
        running = false;
        interrupt();
    }

    @Override
    public void run() {
        running = true;
        while (running) {
            while (portName == null) {
                try {
                    synchronized (this) {
                        wait();
                    }
                } catch (InterruptedException ignored) {
                }
            }
            while (running && portName != null) {
                byte[] cmd = cmdQueue.poll();
                if (cmd == null) break;
                byte[] response = doResponse(cmd);
                try {
                    cmdRespQueue.offer(response, 500, TimeUnit.MILLISECONDS);
                    frames.clear();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            byte[] frame = doResponse("FRAME".getBytes());
            if (frame != null)
                frames.offer(frame);

        }
        close();
    }

    @SuppressWarnings("WeakerAccess")
    public CommFacility() {
        this(null);
    }

    @SuppressWarnings("unused")
    public String getPortName() {
        return portName;
    }

    @SuppressWarnings("WeakerAccess")
    public void setPortName(String portName) {
        this.portName = portName;
        close();
        interrupt();
    }

    @SuppressWarnings("WeakerAccess")
    public void setPortStatusConsumer(BiConsumer<String, Boolean> portStatusConsumer) {
        this.portStatusConsumer = portStatusConsumer;
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

    @SuppressWarnings({"unused", "WeakerAccess"})
    public byte[] getResponse(String command) {
        if (portName == null) return null;
        if ("FRAME".equals(command)) {
            return frames.poll();
        } else {
            try {
                cmdQueue.offer(command.getBytes(StandardCharsets.US_ASCII), 500, TimeUnit.MILLISECONDS);
                return cmdRespQueue.poll(500, TimeUnit.MILLISECONDS);
            } catch (InterruptedException e) {
                throw new RuntimeException();
            }
        }
    }

    private byte[] doResponse(byte[] command) {
        if (!connect()) return null;
        try {
            cmdStream.write(CRLF);
            cmdStream.write(command);
            cmdStream.write(CRLF);
            cmdStream.flush();
            short header = read16(inputStream);
            if ((header & 0x8000) == 0)
                throw new IOException(String.format("Wrong header: %04x at: %d", header, byteCounter.longValue()));
            byte data[] = new byte[header & 0x7FFF];
            for (int b, i = 0; i < data.length; i++) {
                if ((b = inputStream.read()) < 0)
                    throw new IOException(String.format("Unexpected EOF at: %d", byteCounter.longValue()));
                byteCounter.incrementAndGet();
                data[i] = (byte) b;
            }

            return data;
        } catch (IOException e) {
            sendStatus(e.getClass().getSimpleName() + ": " + e.getMessage(), false);
            close();
            return new byte[]{};
        }
    }

    @SuppressWarnings("WeakerAccess")
    public boolean connect() {
        if (portName == null) return false;
        if (oscilloscope == null) {
            try {
                portIdentifier = CommPortIdentifier.getPortIdentifier(portName);
            } catch (NoSuchPortException e) {
                sendStatus("Port is not available", false);
                sleepMe(250);
                return false;
            }
            try {
                oscilloscope = (SerialPort) portIdentifier.open("Oscilloscope", 250);
            } catch (PortInUseException e) {
                sendStatus("Port is in use", false);
                return false;
            }
            if (oscilloscope != null) {
                try {
                    oscilloscope.enableReceiveTimeout(200);
                } catch (UnsupportedCommOperationException e) {
                    System.err.println("Timeout not supported");
                }
                try {
                    inputStream = oscilloscope.getInputStream();
                    cmdStream = oscilloscope.getOutputStream();
                    sendStatus("Connected", true);
                    return true;
                } catch (IOException e) {
                    sendStatus("Port open failed: " + e.getMessage(), false);
                    close();
                }

            }
            return false;
        }
        return connected;
    }

    @Override
    public void close() {
        if (inputStream != null) {
            try {
                inputStream.close();
            } catch (IOException ignore) {
            }
            inputStream = null;
        }
        if (cmdStream != null) {
            try {
                cmdStream.close();
            } catch (IOException ignore) {
            }
            cmdStream = null;
        }
        if (oscilloscope != null) {
            oscilloscope.close();
            oscilloscope = null;
        }
        portIdentifier = null;
    }

    @SuppressWarnings("SameParameterValue")
    private void sleepMe(long millis) {
        if (millis > 0)
            try {
                Thread.sleep(millis);
            } catch (InterruptedException ignored) {
            }
    }

    private short read16(InputStream in) throws IOException {
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
    public boolean isConnected() {
        return connected;
    }

    @SuppressWarnings({"WeakerAccess", "unused"})
    public static String[] ports() {
        return Collections.list(CommPortIdentifier.getPortIdentifiers()).stream()
                .filter(identifier -> identifier.getPortType() == CommPortIdentifier.PORT_SERIAL)
                .map(CommPortIdentifier::getName).toArray(String[]::new);

    }
}
