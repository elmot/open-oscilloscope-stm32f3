package xyz.elmot.oscill;

import fi.iki.elonen.NanoHTTPD;
import fi.iki.elonen.NanoHTTPD.Response.Status;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.WindowConstants;
import java.awt.Desktop;
import java.io.IOException;
import java.io.InputStream;
import java.net.URI;
import java.util.Map;
import java.util.TreeMap;
import java.util.concurrent.TimeUnit;
import java.util.function.Supplier;

/**
 * (c) elmot on 9.3.2017.
 */
public class WebMain extends NanoHTTPD {

    private static final int PORT = 1515;
    private final static Map<String, Resource> staticResources = new TreeMap<>();
    private final CommThread commThread;

    private static class Resource {
        final String mimeType;
        final Supplier<InputStream> data;

        Resource(String mimeType, Supplier<InputStream> data) {
            this.mimeType = mimeType;
            this.data = data;
        }
    }

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
    }

    private WebMain() {
        super(PORT);

        commThread = new CommThread("ttyACM0", null, 5) {
            @Override
            protected void waitForCommand() {
            }
        };
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
        if ("/cmd".equals(session.getUri())) {
            //todo different commands
            Frame frame = null;
            try {
                frame = commThread.getFrames().poll(1200, TimeUnit.MILLISECONDS);
            } catch (InterruptedException ignored) {
            }
            if (frame == null) return responseStatus(Status.NO_CONTENT);
            ShortFlowInputStream shortFlowInputStream = new ShortFlowInputStream(frame.data);
            return newFixedLengthResponse(Status.OK, "application/binary"
                    , shortFlowInputStream, shortFlowInputStream.getSize());
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
    private static void createAndShowGUI() {
        //Create and set up the window.
        JFrame frame = new JFrame("HelloWorldSwing");
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        //Add the ubiquitous "Hello World" label.
        JButton button = new JButton("Open Browser");
        button.addActionListener(e -> {
            try {
                Desktop.getDesktop().browse(new URI("http://localhost:" + PORT + "/"));
            } catch (Exception e1) {
                e1.printStackTrace();
            }
        });
        frame.getContentPane().add(button);

        //Display the window.
        frame.pack();
        frame.setLocationByPlatform(true);
        frame.setVisible(true);

    }

    public static void main(String[] args) throws IOException {
        //Schedule a job for the event-dispatching thread:
        //creating and showing this application's GUI.
        new WebMain().start();
        javax.swing.SwingUtilities.invokeLater(WebMain::createAndShowGUI);
    }
}
