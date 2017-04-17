package xyz.elmot.gencfile.elements;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.StartElement;
import java.io.PrintWriter;

/**
 * (c) elmot on 16.4.2017.
 */
public class Field extends NamedElement implements Comparable<Field>{
    private int bitOffset;
    private int bitWidth;
    private String access;

    public Field() {
        super("field");
    }

    @Override
    protected void processSubTag(XMLEventReader reader, StartElement innerElement) throws XMLStreamException {
        if (readLong(reader, innerElement, "bitOffset", i -> bitOffset = i.intValue())) return;
        if (readLong(reader, innerElement, "bitWidth", i -> bitWidth = i.intValue())) return;
        if (readText(reader, innerElement, "access", s -> access = s)) return;
        super.processSubTag(reader, innerElement);
    }

    public int getBitOffset() {
        return bitOffset;
    }

    public int getBitWidth() {
        return bitWidth;
    }

    @Override
    public int compareTo(Field o) {
        return Long.compare(bitOffset, o.getBitOffset());
    }

    public static void writeUnused(PrintWriter writer, int unusedSize) {
        for (int len = unusedSize; len > 0; len -= 32) {
            writer.printf("      unsigned int : %d; // Reserved\n", Math.min(32, len));
        }
    }

    public int write(int fieldOffset, PrintWriter writer) {
        writeUnused(writer, bitOffset - fieldOffset);
        writer.printf("      unsigned int %s: %d; // %s\n", name, bitWidth, description);
        return bitOffset + bitWidth;
    }
}
