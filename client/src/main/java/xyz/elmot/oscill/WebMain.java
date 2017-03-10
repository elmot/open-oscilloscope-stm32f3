package xyz.elmot.oscill;

import com.sun.xml.internal.messaging.saaj.util.ByteInputStream;
import fi.iki.elonen.NanoHTTPD;
import fi.iki.elonen.NanoHTTPD.Response.Status;
import xyz.elmot.oscill.web.Resource;

import javax.swing.*;
import javax.swing.border.BevelBorder;
import java.awt.*;
import java.io.IOException;
import java.net.URI;
import java.util.Map;
import java.util.TreeMap;
import java.util.concurrent.TimeUnit;
import java.util.function.Consumer;

/**
 * (c) elmot on 9.3.2017.
 */
public class WebMain extends NanoHTTPD {

    private static final int PORT = 1515;
    private final static Map<String, Resource> staticResources = new TreeMap<>();
    private CommThread<byte[]> commThread;
    private JLabel connectStatus;

    private static void registerResource(String name, String mimeType) {
        registerResource(name, name, mimeType);
    }

    private static void registerResource(String name, String realName, String mimeType) {
        staticResources.put("/" + name, new Resource(mimeType, () ->
                WebMain.class.getResourceAsStream(realName))
        );
    }

    static {
        registerResource("content.html", "text/html;encoding=utf-8");
        registerResource("ui.js", "application/javascript");
        registerResource("hw.js", "hw_web.js", "application/javascript");
        registerResource("oscilloscope.css", "text/css");
        registerResource("icon.png", "image/png");
    }

    private WebMain() {
        super(PORT);

    }

    private void openPort(String ttyACM0, Consumer<String> portStatusConsumer) {
        commThread = new CommThread.Bytes(ttyACM0, portStatusConsumer, 5, 0);
        commThread.start();
    }

    @Override
    public Response serve(IHTTPSession session) {
        switch (session.getMethod()) {
            case GET:
                return serveStaticResources(session);
            case POST:
                return serveCommand(session);
            default:
                return responseStatus(Status.METHOD_NOT_ALLOWED);
        }
    }

    private Response serveCommand(IHTTPSession session) {
        if ("/frame".equals(session.getUri())) {
            //todo different commands
            byte[] frame = null;
            try {
                if (commThread != null)
                    frame = commThread.getQueue().poll(1200, TimeUnit.MILLISECONDS);
            } catch (InterruptedException ignored) {
            }
            if (frame == null) return responseStatus(Status.NO_CONTENT);
            return newFixedLengthResponse(Status.OK, "application/binary"
                    , new ByteInputStream(frame, frame.length), frame.length);
        } else return responseStatus(Status.METHOD_NOT_ALLOWED);

    }

    private Response serveStaticResources(IHTTPSession session) {
        String uri = session.getUri();
        if (uri == null || "".equals(uri) || "/".equals(uri)) {
            Response response = responseStatus(Status.REDIRECT);
            response.addHeader("Location", "/content.html");
            return response;
        }
        Resource resource = staticResources.get(uri);
        if (resource != null) {
            return newChunkedResponse(Status.OK, resource.mimeType, resource.data.get());
        }
        return responseStatus(Status.NOT_FOUND);
    }

    private Response responseStatus(Status status) {
        return newFixedLengthResponse(status, NanoHTTPD.MIME_PLAINTEXT, status.getDescription());
    }

    /**
     * Create the GUI and show it.  For thread safety,
     * this method should be invoked from the
     * event-dispatching thread.
     */
    private void createAndShowGUI() {
        //Create and set up the window.
        JFrame frame = new JFrame("HelloWorldSwing");
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.setIconImage(Toolkit.getDefaultToolkit().getImage(WebMain.class.getResource("icon.png")));

        JComboBox<String> portNames = new JComboBox<>(CommThread.ports());

        Container contentPane = frame.getContentPane();
        contentPane.setLayout(new GridBagLayout());
        contentPane.add(new JLabel("Port:"), new GridBagConstraints(0, 0, 1, 1, 0, 0, GridBagConstraints.NORTHWEST,
                GridBagConstraints.BOTH, new Insets(10, 10, 10, 10), 5, 5));
        contentPane.add(portNames, new GridBagConstraints(1, 0, 1, 1, 1, 0, GridBagConstraints.NORTHWEST,
                GridBagConstraints.BOTH, new Insets(10, 10, 10, 10), 5, 5));

        JButton button = new JButton("Open Browser");
        button.addActionListener(e -> {
            try {
                Desktop.getDesktop().browse(new URI("http://localhost:" + PORT + "/"));
            } catch (Exception e1) {
                e1.printStackTrace();
            }
        });


        contentPane.add(button, new GridBagConstraints(0, 1, 2, 1, 1, 0, GridBagConstraints.NORTHWEST,
                GridBagConstraints.HORIZONTAL, new Insets(10, 10, 10, 10), 5, 5));
        connectStatus = new JLabel("--");
        connectStatus.setBorder(BorderFactory.createBevelBorder(BevelBorder.LOWERED));
        contentPane.add(connectStatus, new GridBagConstraints(0, 2, 2, 1, 1, 0, GridBagConstraints.SOUTHWEST,
                GridBagConstraints.HORIZONTAL, new Insets(10, 10, 10, 10), 5, 5));
        portNames.addActionListener(e -> {
                    if (commThread != null)
                        commThread.giveUp();
                    openPort((String) portNames.getSelectedItem(),
                            status -> SwingUtilities.invokeLater(() -> connectStatus.setText(status)));
                }
        );
        portNames.setSelectedItem("ttyACM0");
        //Display the window.
        frame.pack();
        frame.setLocationByPlatform(true);
        frame.setVisible(true);

    }

    public static void main(String[] args) throws IOException {
        //Schedule a job for the event-dispatching thread:
        //creating and showing this application's GUI.
        WebMain webMain = new WebMain();
        webMain.start();
        javax.swing.SwingUtilities.invokeLater(webMain::createAndShowGUI);
    }
}
