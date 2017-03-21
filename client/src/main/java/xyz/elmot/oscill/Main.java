package xyz.elmot.oscill;

import java.util.function.Consumer;

public class Main {
    @SuppressWarnings("WeakerAccess")
    public static String PORT_NAME = "ttyACM0";

    public static void main(String[] args) {
        Consumer<String[]> mainRunner = BrowserMain::main;
        boolean disableOpenGl = true;//because of bug in linux
        for (String arg : args) {
            switch (arg) {
                case "-web":
                    mainRunner = WebMain::main;
                    break;
                case "-opengl":
                    disableOpenGl = false;
                    break;
                case "-help":
                    printUsage();
                    return;
                default:
                    PORT_NAME = arg;
            }
        }
        if (disableOpenGl) {
            System.setProperty("prism.order", "sw");
        }
        mainRunner.accept(args);
    }

    private static void printUsage() {
        System.out.println("Usage: java[w] -jar osc-client.jar [-web] [-opengl] [-help] [portname]");
    }
}
