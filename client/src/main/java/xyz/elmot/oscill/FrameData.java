package xyz.elmot.oscill;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

import static xyz.elmot.oscill.FrameData.TYPE.NORMAL;
import static xyz.elmot.oscill.FrameData.TYPE.TRIGGERED;


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

    public static FrameData newFrameData(byte[] binary) {
        if(binary == null || binary.length == 0) return null;
        ByteBuffer byteBuffer = ByteBuffer.wrap(binary).order(ByteOrder.LITTLE_ENDIAN);
        if (byteBuffer.get(0) != 'F' ||
                byteBuffer.get(1) != 'R') {
            System.err.println("Frame error");
            return null;
        }
        short head = byteBuffer.getShort(2);
        int bits = 12;
        int channels = 3;
        int len = head & 0xFFF;
        TYPE type = ((head & 0x4000) != 0) ? TRIGGERED : NORMAL;
        short[] row = new short[len];
        for (int i = 0; i < row.length; i++) {
            row[i] = byteBuffer.getShort(4 + i * 2);
        }
        short[][]data = new short[][]{row};
        return new FrameData(type,channels,len,bits, data);
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
