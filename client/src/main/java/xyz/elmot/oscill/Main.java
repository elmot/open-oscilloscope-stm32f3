package xyz.elmot.oscill;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.collections.ObservableList;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.input.KeyCombination;
import javafx.stage.Stage;
import javafx.stage.StageStyle;


import java.util.Iterator;
import java.util.concurrent.ConcurrentLinkedQueue;

/**
 * (c) elmot on 9.2.2017.
 */
public class Main extends Application {

    @Override
    public void start(Stage stage) throws Exception {
        stage.setTitle("TeleFence");
        stage.setFullScreenExitKeyCombination(KeyCombination.keyCombination("F11"));
        NumberAxis xAxis = new NumberAxis();
        NumberAxis yAxis = new NumberAxis(-16, 16, 2);
        LineChart<Number, Number> chart = new LineChart<>(xAxis, yAxis);
        chart.setAnimated(false);
        chart.setCreateSymbols(false);
        xAxis.setTickLabelsVisible(false);
        xAxis.setTickMarkVisible(false);
        xAxis.setMinorTickVisible(false);

        yAxis.setForceZeroInRange(true);
        for (int j = 0; j < 7; j++) {
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
        stage.initStyle(StageStyle.TRANSPARENT);
        stage.setFullScreen(true);
        scene.setFill(null);
        scene.getStylesheets().add("styles.css");
    }

    public static void main(String[] args) {
        launch(args);
    }

    private class FxUpdate implements Runnable {
        private final XYChart<Number, Number> chart;

        public FxUpdate(XYChart<Number, Number> chart) {
            this.chart = chart;
        }

        @Override
        public void run() {
            ObservableList<XYChart.Series<Number, Number>> serie = chart.getData();

            Platform.runLater(this);


        }
    }

}
