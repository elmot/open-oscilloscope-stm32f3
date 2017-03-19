package xyz.elmot.oscill;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.ShortBuffer;
import java.util.Arrays;

import static xyz.elmot.oscill.FrameData.TYPE.*;


/**
 * (c) elmot on 2.3.2017.
 */
public class FrameData {
    enum TYPE {
        NORMAL,
        TRIGGERED
    }

    final int len;
    final int channels;
    final int bits;
    final short[][] data;
    final TYPE type;

    public FrameData(byte[] binary) {
        ByteBuffer byteBuffer = ByteBuffer.wrap(binary).order(ByteOrder.LITTLE_ENDIAN);
        if (byteBuffer.get(0) != 'F' ||
                byteBuffer.get(1) != 'R') {
            throw new RuntimeException("Frame error");
        }
        short head = byteBuffer.getShort(2);
        bits = 12;
        channels = 3;
        len = head & 0xFFF;
        type = ((head & 0x4000) != 0) ? TRIGGERED : NORMAL;
        short[] row = new short[len];
        for (int i = 0; i < row.length; i++) {
            row[i] = byteBuffer.getShort(4 + i * 2);
        }
        data = new short[][]{row};
    }

    public FrameData(TYPE type, int channels, int len, int bits, short[][] data) {
        this.len = len;
        this.channels = channels;
        this.bits = bits;
        this.data = data;
        this.type = type;
    }

    @Override
    public String toString() {
        return String.format("FRAME:[%c,%d*%d;%db]%s",
                type == NORMAL ? 'n' : 'T',
                len, channels, bits,
                len == data[0].length ? "" : "BROKEN LENGTH!"
        );
    }
}
