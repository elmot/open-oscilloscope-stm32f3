package xyz.elmot.oscill;

import fi.iki.elonen.NanoHTTPD;
import fi.iki.elonen.NanoHTTPD.Response.Status;
import org.apache.commons.io.IOUtils;
import xyz.elmot.oscill.web.Resource;

import javax.swing.*;
import javax.swing.border.BevelBorder;
import javax.swing.event.PopupMenuEvent;
import javax.swing.event.PopupMenuListener;
import java.awt.*;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.net.URI;
import java.nio.charset.StandardCharsets;
import java.util.Map;
import java.util.TreeMap;

/**
 * (c) elmot on 9.3.2017.
 */
public class WebMain extends NanoHTTPD {

    private static final int PORT = 1515;
    private final static Map<String, Resource> staticResources = new TreeMap<>();
    private CommFacility<byte[]> commFacility = new CommFacility<>(b -> b);
    private JLabel connectStatus;
    private String connectionStatusText = "Not Started";
    private boolean connectionStatusError = true;

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

    @Override
    public Response serve(IHTTPSession session) {
        try {
            switch (session.getMethod()) {
                case GET:
                    return serveStaticResources(session);
                case POST:
                    return serveCommand((HTTPSession) session);
                default:
                    return responseStatus(Status.METHOD_NOT_ALLOWED);
            }
        } catch (IOException e) {
            return newFixedLengthResponse(Status.INTERNAL_ERROR, "text/plain", e.getMessage());
        }
    }

    private Response serveCommand(HTTPSession session) throws IOException {
        if ("/frame".equals(session.getUri())) {
            byte[] frame = commFacility.getDataResponse();
            if (frame == null) {
                Response response = newFixedLengthResponse(Status.NO_CONTENT, NanoHTTPD.MIME_PLAINTEXT, "");
                if (connectionStatusError) {
                    response.addHeader("X-Comm-Error", connectionStatusText);
                }
                return response;
            } else {
                return newFixedLengthResponse(Status.OK, "application/binary"
                        , new ByteArrayInputStream(frame), frame.length);
            }
        } else if ("/cmd".equals(session.getUri())) {
            long bodySize = session.getBodySize();
            if (bodySize >= 1000000) {
                return responseStatus(Status.PAYLOAD_TOO_LARGE);
            }
            byte[] bytes = new byte[(int) bodySize];
            IOUtils.read(session.getInputStream(), bytes);
            String result = commFacility.getCommandResponse(new String(bytes, StandardCharsets.US_ASCII));
            if (result.isEmpty()) {
                Response response = responseStatus(Status.NO_CONTENT);
                if (connectionStatusError) {
                    response.addHeader("X-Comm-Error", connectionStatusText);
                }
                return response;
            } else {
                return newFixedLengthResponse(Status.OK, "text/plain", result);
            }
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
        JFrame frame = new JFrame("Oscilloscope server");
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.setIconImage(Toolkit.getDefaultToolkit().getImage(WebMain.class.getResource("icon_128.png")));

        JComboBox<String> portNames = new JComboBox<>(CommFacility.ports());

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
        connectStatus = new JLabel(connectionStatusText);
        connectStatus.setBorder(BorderFactory.createBevelBorder(BevelBorder.LOWERED));
        commFacility.setPortStatusConsumer((text, q) -> {
                    connectionStatusText = text;
                    connectionStatusError = !q;
                    SwingUtilities.invokeLater(() ->
                            {
                                connectStatus.setText(connectionStatusText);
                                connectStatus.setForeground(q ? Color.GREEN.darker() : Color.RED.darker());
                            }
                    );
                }
        );
        contentPane.add(connectStatus, new GridBagConstraints(0, 2, 2, 1, 1, 0, GridBagConstraints.SOUTHWEST,
                GridBagConstraints.HORIZONTAL, new Insets(10, 10, 10, 10), 5, 5));
        portNames.addActionListener(e -> {
                    commFacility.close();
                    commFacility.setPortName((String) portNames.getSelectedItem());
                }
        );
        portNames.addPopupMenuListener(new PopupMenuListener() {
            @Override
            public void popupMenuWillBecomeVisible(PopupMenuEvent e) {

                DefaultComboBoxModel<String> model = new DefaultComboBoxModel<>(CommFacility.ports());
                model.setSelectedItem(portNames.getSelectedItem());
                portNames.setModel(model);
            }

            @Override
            public void popupMenuWillBecomeInvisible(PopupMenuEvent e) {

            }

            @Override
            public void popupMenuCanceled(PopupMenuEvent e) {

            }
        });
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

    @Override
    protected boolean useGzipWhenAccepted(Response r) {
        return false;
    }
}
