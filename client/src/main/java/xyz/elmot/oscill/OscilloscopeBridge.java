package xyz.elmot.oscill;

/**
 * (c) elmot on 7.3.2017.
 */
public class OscilloscopeBridge {
    private Object statusChange;

    public void test() {
        System.out.println("test");
    }
    public Object getStatusChange() {
        return statusChange;
    }

    public void setStatusChange(Object statusChange) {
        this.statusChange = statusChange;
    }

    public void sendCommand(String name, String value) {
        System.out.printf("%s: %s\n", name, value);
    }
}
