package xyz.elmot.oscill;

import com.sun.xml.internal.messaging.saaj.util.ByteInputStream;
import fi.iki.elonen.NanoHTTPD;

import javax.swing.*;
import java.awt.*;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URI;
import java.util.Map;
import java.util.TreeMap;
import java.util.concurrent.CountDownLatch;
import java.util.function.Supplier;

/**
 * (c) elmot on 9.3.2017.
 */
public class WebMain extends NanoHTTPD {

    private static final int PORT = 1515;
    private final static Map<String, Resource> staticResources = new TreeMap<>();

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
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        InputStream inputStream = WebMain.class.getResourceAsStream(realName);
        try {
            for (int b; (b = inputStream.read()) >= 0; ) {
                baos.write(b);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        byte[] bytes = baos.toByteArray();
        staticResources.put("/" + name, new Resource(mimeType, () -> new ByteInputStream(bytes, bytes.length)));

    }

    static {
        registerResource("content.html", "text/html;encoding=utf-8");
        registerResource("ui.js", "application/javascript");
        registerResource("hw.js", "hw_web.js", "application/javascript");
        registerResource("oscilloscope.css", "text/css");
    }

    private WebMain() {
        super(PORT);
        CountDownLatch
        new CommThread("ttyACM0", null) {
            @Override
            protected void waitForCommand() {

            }
        };
    }

    @Override
    public Response serve(IHTTPSession session) {
        switch (session.getMethod()) {
            case GET:
                return serveStaticResources(session);
            case POST:
                return serveCommand(session);
            default:
                return responsStatus(Response.Status.METHOD_NOT_ALLOWED);
        }
    }

    private Response serveCommand(IHTTPSession session) {
        return null;
    }

    private Response serveStaticResources(IHTTPSession session) {
        String uri = session.getUri();
        if (uri == null || "".equals(uri) || "/".equals(uri)) {
            Response response = responsStatus(Response.Status.REDIRECT);
            response.addHeader("Location", "/content.html");
            return response;
        }
        Resource resource = staticResources.get(uri);
        if (resource != null) {
            return newChunkedResponse(Response.Status.OK, resource.mimeType, resource.data.get());
        }
        return responsStatus(Response.Status.NOT_FOUND);
    }

    private Response responsStatus(Response.Status status) {
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
