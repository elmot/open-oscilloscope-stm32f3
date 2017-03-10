package xyz.elmot.oscill;

import java.util.Arrays;

/**
 * (c) elmot on 2.3.2017.
 */
public class Frame {
    enum TYPE {
        NORMAL,
        TRIGGERED
    }

    final int len;
    final int channels;
    final int bits;
    final short[][] data;
    final TYPE type;

    public Frame(TYPE type, int channels, int len, int bits, short[][] data) {
        this.len = len;
        this.channels = channels;
        this.bits = bits;
        this.data = data;
        this.type = type;
    }

    @Override
    public String toString() {
        return String.format("FRAME:[%c,%d*%d;%db]%s",
                type == TYPE.NORMAL ? 'n' : 'T',
                len, channels, bits,
                len == data[0].length ? "" : "BROKEN LENGTH!"
        );
    }
}
