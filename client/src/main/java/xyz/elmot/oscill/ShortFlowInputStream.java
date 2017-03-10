package xyz.elmot.oscill;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.*;
import java.util.Arrays;
import java.util.stream.Collectors;

/**
 * (c) elmot on 10.3.2017.
 */
public class ShortFlowInputStream extends InputStream {
    private final int size;
    private final short[][] data;
    private InputStream buffer;
    private int i = 0;

    @SuppressWarnings("WeakerAccess")
    public ShortFlowInputStream(short[][] data) {
        this.data = data;
        size = Arrays.stream(data).mapToInt(bytes -> bytes.length).sum() * 2;
    }

    @SuppressWarnings("WeakerAccess")
    public int getSize() {
        return size;
    }

    @Override
    public int read() throws IOException {
        while (true) {
            if (buffer != null) {
                int res = buffer.read();
                if (res >= 0) return res;
                buffer = null;
            }
            if (i == data.length) return -1;

            short[] row = data[i++];
            if (row == null || row.length == 0) {
                continue;
            }
            ByteBuffer byteBuffer = ByteBuffer.allocate(row.length * 2).order(ByteOrder.LITTLE_ENDIAN);
            byteBuffer.asShortBuffer().put(row);
            buffer = new ByteArrayInputStream(byteBuffer.array());
        }
    }
}
