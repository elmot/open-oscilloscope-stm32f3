package xyz.elmot.oscill;

import javafx.animation.AnimationTimer;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.collections.ObservableList;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.input.KeyCombination;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;
import purejavacomm.NoSuchPortException;
import purejavacomm.PortInUseException;


import java.io.IOException;

/**
 * (c) elmot on 9.2.2017.
 */
public class Main extends Application {

    private static CommThread commThread;
    private final long[] frameTimes = new long[20];
    private int frameTimeIndex = 0 ;
    private boolean arrayFilled = false ;
    private LineChart<Number, Number> chart;

    @Override
    public void start(Stage stage) throws Exception {
        AnimationTimer frameRateMeter = new AnimationTimer() {

            @Override
            public void handle(long now) {
                long oldFrameTime = frameTimes[frameTimeIndex] ;
                frameTimes[frameTimeIndex] = now ;
                frameTimeIndex = (frameTimeIndex + 1) % frameTimes.length ;
                if (frameTimeIndex == 0) {
                    arrayFilled = true ;
                }
                if (arrayFilled) {
                    long elapsedNanos = now - oldFrameTime ;
                    long elapsedNanosPerFrame = elapsedNanos / frameTimes.length ;
                    double frameRate = 1_000_000_000.0 / elapsedNanosPerFrame ;
                    stage.setTitle(String.format("Oscilloscope. FPS: %.3f", frameRate));
                }
            }
        };
        frameRateMeter.start();

        stage.setOnCloseRequest(new EventHandler<WindowEvent>() {
            @Override
            public void handle(WindowEvent event) {
                try {
                    commThread.giveUp();
                    stop();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

        stage.setTitle("Oscilloscope");
        stage.setFullScreenExitKeyCombination(KeyCombination.keyCombination("F11"));
        NumberAxis xAxis = new NumberAxis();
        NumberAxis yAxis = new NumberAxis(0, 1000, 2);
        chart = new LineChart<>(xAxis, yAxis);
        chart.setAnimated(false);
        chart.setCreateSymbols(false);
        xAxis.setTickLabelsVisible(false);
        xAxis.setTickMarkVisible(false);
        xAxis.setMinorTickVisible(false);

        yAxis.setForceZeroInRange(true);
        for (int j = 0; j < 2; j++) {
            XYChart.Series<Number, Number> series = new XYChart.Series<>();
            for (int i = 0; i < 1; i++) series.getData().add(new XYChart.Data<>(i, -1d));
            chart.getData().add(series);
        }
        Scene scene = new Scene(chart);
        decorateStage(stage, scene);
        stage.setScene(scene);
        stage.setOnCloseRequest(event -> Platform.exit());
        stage.show();
        Platform.runLater(new FxUpdate(chart));
    }



    private void decorateStage(Stage stage, Scene scene) {
//        stage.initStyle(StageStyle.TRANSPARENT);
//        stage.setFullScreen(true);
        scene.setFill(null);
        scene.getStylesheets().add("styles.css");
    }

    public static void main(String[] args) throws NoSuchPortException, PortInUseException, IOException, InterruptedException {

        commThread = new CommThread("ttyACM0", System.err::println);
        commThread.start();
        try {
            launch(args);
        } finally {
            commThread.giveUp();
        }

    }

    private class FxUpdate implements Runnable {
        private final XYChart<Number, Number> chart;

        public FxUpdate(XYChart<Number, Number> chart) {
            this.chart = chart;
        }

        @Override
        public void run() {
            ObservableList<XYChart.Series<Number, Number>> serie = chart.getData();
            try {
                Frame take = commThread.getFrames().take();
                int serieIndex = take.type == Frame.TYPE.TRIGGERED ? 1 : 0;
                ObservableList<XYChart.Data<Number, Number>> data = serie.get(serieIndex).getData();
                int[] line = take.data[0];
                XYChart.Data<Number, Number> chartData []= new XYChart.Data[line.length];
                for (int i = 0; i < line.length; i++) {
                    chartData[i] = new XYChart.Data<>(i,line[i]);
                }
                data.clear();
                data.setAll(chartData);
            } catch (Exception e) {
                e.printStackTrace();
            }

            Platform.runLater(this);


        }
    }

}
