package xyz.elmot.oscill;

import com.sun.javafx.webkit.WebConsoleListener;
import javafx.animation.AnimationTimer;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCombination;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;
import javafx.stage.Stage;
import netscape.javascript.JSObject;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 * (c) elmot on 9.2.2017.
 */
public class BrowserMain extends Application {

    private static CommThread commThread;
    private final long[] frameTimes = new long[20];
    private int frameTimeIndex = 0;
    private boolean arrayFilled = false;

    @Override
    public void start(Stage stage) throws Exception {
        stage.getIcons().add( new Image( BrowserMain.class.getResourceAsStream( "icon.png" )));
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
//        Platform.runLater(new FxUpdate(chart));
    }

    private WebView createWebView() {
        WebConsoleListener.setDefaultListener(
                (webView1, message, lineNumber, sourceId) ->
                        System.err.printf("%s[%d]: %s\n\r", sourceId, lineNumber, message));

        WebView webView = new WebView();
        webView.setContextMenuEnabled(false);

        WebEngine engine = webView.getEngine();
        engine.setOnAlert(event -> System.out.println("event.getData() = " + event.getData()));
        engine.setJavaScriptEnabled(true);

        engine.load(BrowserMain.class.getResource("content.html").toExternalForm());
        JSObject jsobj = (JSObject) engine.executeScript("window");
        jsobj.setMember("oscilloscope", new OscilloscopeBridge());
        return webView;
    }


    private void decorateStage(Stage stage, Scene scene) {
//        stage.initStyle(StageStyle.TRANSPARENT);
//        stage.setFullScreen(true);
        scene.setFill(null);
//        scene.getStylesheets().add("root.css");
    }

    public static void main(String[] args) {

        commThread = new CommThread("/dev/ttyACM0", System.err::println);
        commThread.start();
        try {
            launch(args);
        } finally {
            commThread.giveUp();
        }

    }

/*
    private class FxUpdate implements Runnable {

        @Override
        public void run() {
            ObservableList<XYChart.Series<Number, Number>> serie = chart.getData();
            try {
                Frame take = commThread.getFrames().take();
                int serieIndex = take.type == Frame.TYPE.TRIGGERED ? 1 : 0;
                ObservableList<XYChart.Data<Number, Number>> data = serie.get(serieIndex).getData();
                int[] line = take.data[0];
//                XYChart.Data<Number, Number> chartData []= new XYChart.Data[line.length];
                for (int i = 0; i < data.size(); i++) {
                    data.get(i).setYValue(line[i]);
                }
                for (int i = data.size(); i < line.length; i++) {
                    data.add(new XYChart.Data<>(i,line[i]));
                }
//                data.setAll(chartData);
            } catch (Exception e) {
                e.printStackTrace();
            }

            Platform.runLater(this);


        }
    }
*/

}
