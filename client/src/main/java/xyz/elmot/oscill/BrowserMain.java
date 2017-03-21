package xyz.elmot.oscill;

import com.sun.javafx.collections.ObservableListWrapper;
import com.sun.javafx.webkit.WebConsoleListener;
import javafx.animation.AnimationTimer;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.beans.value.ObservableValue;
import javafx.concurrent.Worker;
import javafx.scene.Scene;
import javafx.scene.control.ChoiceBox;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCombination;
import javafx.scene.layout.BorderPane;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;
import javafx.stage.Stage;
import netscape.javascript.JSObject;

import java.io.BufferedReader;
import java.io.StringReader;
import java.util.Arrays;

import static xyz.elmot.oscill.Main.PORT_NAME;

/**
 * (c) elmot on 9.2.2017.
 */
public class BrowserMain extends Application {
    private final static CommFacility<FrameData> commFacility = new CommFacility<>(FrameData::newFrameData);
    private final long[] frameTimes = new long[20];
    private int frameTimeIndex = 0;
    private boolean arrayFilled = false;
    private WebEngine webEngine;
    private Oscilloscope oscilloscope;
    private JSObject jsDataToDraw;
    private JSObject jsWindow;

    @Override
    public void start(Stage stage) throws Exception {
        stage.getIcons().add(new Image(BrowserMain.class.getResourceAsStream("icon_128.png")));
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
                commFacility.giveUp();
                stop();
            } catch (Exception e) {
                e.printStackTrace();
            }
        });

        stage.setTitle("Oscilloscope");
        stage.setFullScreenExitKeyCombination(KeyCombination.keyCombination("F11"));
        WebView webView = createWebView();
        ChoiceBox<String> ports = new ChoiceBox<>();
        listPortsToChoiceBox(ports);
        ports.setValue(PORT_NAME);
        ports.onShowingProperty().set(e ->
                listPortsToChoiceBox(ports));
        BorderPane root = new BorderPane(webView, ports, null, null, null);
        Scene scene = new Scene(root);
        decorateStage(stage, scene);
        stage.setScene(scene);
        stage.setOnCloseRequest(event -> Platform.exit());
        stage.show();
    }

    private void listPortsToChoiceBox(ChoiceBox<String> ports) {
        ports.setItems(
                new ObservableListWrapper<>(Arrays.asList(CommFacility.ports())
                ));
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

        webEngine.getLoadWorker().stateProperty().addListener((ObservableValue<? extends Worker.State> ov, Worker.State oldState, Worker.State newState) -> {

            if (newState == Worker.State.SUCCEEDED) {
                jsWindow = (JSObject) webEngine.executeScript("window");
                oscilloscope = new Oscilloscope();
                jsWindow.setMember("osc", oscilloscope);
                jsDataToDraw = (JSObject) webEngine.executeScript("[]");
                commFacility.setPortStatusConsumer(this::showStatus);
                commFacility.setPortName(PORT_NAME);
                Platform.runLater(new FxUpdate());
            }

        });
        webEngine.load(BrowserMain.class.getResource("content.html").toExternalForm());
        return webView;
    }

    private void showStatus(String text, Boolean connected) {
        printStatus(text, connected);
        Platform.runLater(() ->
                jsWindow.call("showStatus", connected ? "" : text)
        );

    }


    @SuppressWarnings("unused")
    private void decorateStage(Stage stage, Scene scene) {
//        stage.initStyle(StageStyle.TRANSPARENT);
//        stage.setFullScreen(true);
        scene.setFill(null);
//        scene.getStylesheets().add("root.css");
    }

    public static void main(String[] args) {
        try {
            launch(args);
        } finally {
            commFacility.giveUp();
        }

    }

    private static void printStatus(String text, boolean connected) {
        System.err.println((connected ? "CONNECTED: " : "DISCONNECTED: ") + text);
    }

    private class FxUpdate implements Runnable {
        private int configDelayCounter = 0;

        @Override
        public void run() {

            try {
                if (configDelayCounter++ == 10) {
                    configDelayCounter = 0;
                    String conf = commFacility.getCommandResponse("CONF");
                    try (BufferedReader reader = new BufferedReader(new StringReader(conf))) {
                        for (String s; (s = reader.readLine()) != null; ) {
                            int eqPos = s.indexOf('=');
                            if (eqPos < 1) continue;
                            String name = s.substring(0, eqPos);
                            String value = s.substring(eqPos + 1);
                            jsWindow.call("updateGuiControl", name, value);
                        }
                    }
                }
                FrameData  frame = commFacility.getDataResponse();
                if (frame != null) {
                    int serieIndex = frame.type == FrameData.TYPE.TRIGGERED ? 1 : 0;
                    for (int i = 0; i < frame.data.length; i++) {
                        int index = i * 2 + serieIndex;
                        jsDataToDraw.setSlot(index, frame.data[i]);
                    }
                    jsWindow.call("drawData", jsDataToDraw);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            Platform.runLater(this);

        }
    }

    public class Oscilloscope {

        @SuppressWarnings("unused")
        public void sendCommand(String cmd) {
            commFacility.getCommandResponse(cmd);
        }
    }
}
