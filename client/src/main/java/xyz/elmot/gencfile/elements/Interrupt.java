package xyz.elmot.gencfile.elements;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.StartElement;

/**
 * (c) elmot on 16.4.2017.
 */
public class Interrupt extends NamedElement implements Copyable {
    int value;

    public int getValue() {
        return value;
    }

    public Interrupt() {
        super("interrupt");
    }

    @Override
    protected void processSubTag(XMLEventReader reader, StartElement innerElement) throws XMLStreamException {
        if (readLong(reader, innerElement, "value", i -> value = i.intValue())) return;
        super.processSubTag(reader, innerElement);
    }
}
