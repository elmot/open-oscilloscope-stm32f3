package xyz.elmot.oscill;

import purejavacomm.*;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Objects;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.atomic.AtomicLong;
import java.util.function.Consumer;

/**
 * (c) elmot on 2.3.2017.
 */
public abstract class CommThread extends Thread {
    private static final int N_CHANNELS = 1;/*todo*/
    private final String portName;
    private final Consumer<String> portStatusConsumer;
    private volatile boolean running = true;
    private final BlockingQueue<Frame> frames = new ArrayBlockingQueue<>(2);
    private String status;
    private final AtomicLong byteCounter = new AtomicLong(0);

    @SuppressWarnings("WeakerAccess")
    public CommThread(String portName, Consumer<String> portStatusConsumer) {
        setDaemon(true);
        this.portName = portName;
        this.portStatusConsumer = portStatusConsumer;
        sendStatus("Not started");
    }

    private void sendStatus(String newStatus) {
        if (portStatusConsumer != null && !Objects.equals(newStatus, this.status)) {
            portStatusConsumer.accept(newStatus);
        }
        this.status = newStatus;
    }

    @SuppressWarnings("WeakerAccess")
    public void giveUp() {
        running = false;
        interrupt();
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
                    sendStatus("Port is not available");
                    sleepMe(250);
                }
            }
            for (oscilloscope = null; running && oscilloscope == null && portIdentifier != null; ) {
                try {
                    oscilloscope = (SerialPort) portIdentifier.open("Oscilloscope", 250);
                } catch (PortInUseException e) {
                    sendStatus("Port is in use");
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
                    sendStatus("Connected");
                    byteCounter.set(0);
                    while (running) {
                        waitForCommand();
                        cmdStream.write("\nFRAME\n".getBytes());
                        int head = read16(inputStream);
                        if ((head & 0x8000) == 0) {
                            sendStatus("Broken header");
                            break;
                        }
                        int len = (head & 0xfff) / N_CHANNELS;
                        int data[] = new int[len];
                        for (int i = 0; i < data.length; i++) {
                            data[i] = read16(inputStream);
//                            data[i] = (int) (Math.random() * 1024);
                        }
                        Frame.TYPE type = Math.random() < 0.1 ? Frame.TYPE.NORMAL : Frame.TYPE.TRIGGERED;
                        Frame frame = new Frame(type, N_CHANNELS,
                                len, 12, new int[][]{data});
                        try {
                            frames.put(frame);
                        } catch (InterruptedException ignored) {
                        }
                    }

                } catch (IOException e) {
                    sendStatus("Port exchange error");
                } finally {
                    oscilloscope.close();
                }
            }
        }
    }

     abstract protected void waitForCommand();

    @SuppressWarnings("SameParameterValue")
    private void sleepMe(long millis) {
        try {
            Thread.sleep(millis);
        } catch (InterruptedException ignored) {
        }
    }


    private int read16(InputStream in) throws IOException {
        int val = in.read();
        if (val < 0) throw new IOException("unexpected EOF at " + byteCounter);
        byteCounter.incrementAndGet();
        int c = in.read();
        if (c < 0) throw new IOException("unexpected EOF at " + byteCounter);
        byteCounter.incrementAndGet();
        val |= c * 256;
        return val;
    }

    @SuppressWarnings("unused")
    public boolean isRunning() {
        return running;
    }

    @SuppressWarnings("WeakerAccess")
    public BlockingQueue<Frame> getFrames() {
        return frames;
    }

/*
    public boolean isConnected() {
        //todo
    }
*/

    //todo list ports
}
