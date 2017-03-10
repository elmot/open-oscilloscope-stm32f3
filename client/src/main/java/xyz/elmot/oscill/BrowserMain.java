package xyz.elmot.oscill;

import com.sun.javafx.webkit.WebConsoleListener;
import javafx.animation.AnimationTimer;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.concurrent.Worker;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCombination;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;
import javafx.stage.Stage;
import netscape.javascript.JSObject;

/**
 * (c) elmot on 9.2.2017.
 */
public class BrowserMain extends Application {

    private static CommThread.Frame commThread;
    private final long[] frameTimes = new long[20];
    private int frameTimeIndex = 0;
    private boolean arrayFilled = false;
    private WebEngine webEngine;

    @Override
    public void start(Stage stage) throws Exception {
        stage.getIcons().add(new Image(BrowserMain.class.getResourceAsStream("icon.png")));
        AnimationTimer frameRateMeter = new AnimationTimer() {

            @Override
            public void handle(long now) {
                long oldFrameTime = frameTimes[frameTimeIndex];
                frameTimes[frameTimeIndex] = now;
                frameTimeIndex = (frameTimeIndex + 1) % frameTimes.length;
                if (frameTimeIndex == 0) {
                    arrayFilled = true;
                }
                if (arrayFilled) {
                    long elapsedNanos = now - oldFrameTime;
                    long elapsedNanosPerFrame = elapsedNanos / frameTimes.length;
                    double frameRate = 1_000_000_000.0 / elapsedNanosPerFrame;
                    stage.setTitle(String.format("Oscilloscope. FPS: %.3f", frameRate));
                }
            }
        };
        frameRateMeter.start();

        stage.setOnCloseRequest(event -> {
            try {
                commThread.giveUp();
                stop();
            } catch (Exception e) {
                e.printStackTrace();
            }
        });

        stage.setTitle("Oscilloscope");
        stage.setFullScreenExitKeyCombination(KeyCombination.keyCombination("F11"));
        WebView webView = createWebView();
        Scene scene = new Scene(webView);
        decorateStage(stage, scene);
        stage.setScene(scene);
        stage.setOnCloseRequest(event -> Platform.exit());
        stage.show();
        Platform.runLater(new FxUpdate());
    }

    private WebView createWebView() {
        WebConsoleListener.setDefaultListener(
                (webView1, message, lineNumber, sourceId) ->
                        System.err.printf("%s[%d]: %s\n\r", sourceId, lineNumber, message));

        WebView webView = new WebView();
        webView.setContextMenuEnabled(false);

        webEngine = webView.getEngine();
        webEngine.setOnAlert(event -> System.out.println("Alert: " + event.getData()));
        webEngine.setJavaScriptEnabled(true);

        webEngine.getLoadWorker().stateProperty().addListener((ov, oldState, newState) -> {

            if (newState == Worker.State.SUCCEEDED) {
                System.out.println("READY");
                JSObject jsobj = (JSObject) webEngine.executeScript("window");
                jsobj.setMember("osc", new OscilloscopeBridge());
            }

        });
        webEngine.load(BrowserMain.class.getResource("content.html").toExternalForm());
        return webView;
    }


    @SuppressWarnings("unused")
    private void decorateStage(Stage stage, Scene scene) {
//        stage.initStyle(StageStyle.TRANSPARENT);
//        stage.setFullScreen(true);
        scene.setFill(null);
//        scene.getStylesheets().add("root.css");
    }

    public static void main(String[] args) {

        commThread = new CommThread.Frame("ttyACM0", System.err::println, 2, 25);
        commThread.start();
        try {
            launch(args);
        } finally {
            commThread.giveUp();
        }

    }

    private class FxUpdate implements Runnable {
        FxUpdate() {
        }

        @Override
        public void run() {

            JSObject dataToDraw = (JSObject) webEngine.executeScript("[]");
            try {
                FrameData take = commThread.getQueue().take();
                int serieIndex = take.type == FrameData.TYPE.TRIGGERED ? 1 : 0;
                for (int i = 0; i < take.data.length; i++) {
                    int index = i * 2 + serieIndex;
                    dataToDraw.setSlot(index, take.data[i]);
                }
                JSObject jsWindow = (JSObject) webEngine.executeScript("window");
                jsWindow.call("drawData", dataToDraw);
            } catch (Exception e) {
                e.printStackTrace();
            }

            Platform.runLater(this);


        }
    }

    public class OscilloscopeBridge {
        private Object statusChange;


        @SuppressWarnings("unused")
        public Object getStatusChange() {
            return statusChange;
        }

        @SuppressWarnings("unused")
        public void setStatusChange(Object statusChange) {
            this.statusChange = statusChange;
        }

        @SuppressWarnings("unused")
        public void sendCommand(String name, String value) {
            System.out.printf("%s: %s\n", name, value);
        }
    }
}
