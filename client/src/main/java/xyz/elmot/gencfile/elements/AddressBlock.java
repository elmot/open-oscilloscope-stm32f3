package xyz.elmot.gencfile.elements;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.StartElement;

/**
 * (c) elmot on 16.4.2017.
 */
public class AddressBlock extends CommonElement implements Comparable<AddressBlock>, Copyable {
    private String usage;
    private long offset;
    private long size;

    public AddressBlock() {
        super("addressBlock");
    }

    @Override
    protected void processSubTag(XMLEventReader reader, StartElement innerElement) throws XMLStreamException {
        if (readText(reader, innerElement, "usage", i -> usage = i)) return;
        if (readLong(reader, innerElement, "offset", i -> offset = i)) return;
        if (readLong(reader, innerElement, "size", i -> size = i)) return;
        super.processSubTag(reader, innerElement);

    }

    public String getUsage() {
        return usage;
    }

    public long getOffset() {
        return offset;
    }

    public long getSize() {
        return size;
    }

    @Override
    public int compareTo(AddressBlock o) {
        return Long.compare(offset, o.getOffset());
    }

    @Override
    public void copyFrom(Copyable o) {
        AddressBlock another = (AddressBlock) o;
        usage = another.usage;
        offset = another.offset;
        size = another.size;
    }
}
