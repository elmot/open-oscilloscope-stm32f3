package xyz.elmot.gencfile.elements;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.Attribute;
import javax.xml.stream.events.StartElement;
import javax.xml.stream.events.XMLEvent;
import java.util.Iterator;
import java.util.function.Consumer;

import static org.junit.Assert.assertEquals;

/**
 * (c) elmot on 16.4.2017.
 */
@SuppressWarnings("WeakerAccess")
public abstract class CommonElement {

    private final String tagName;

    public CommonElement(String tagName) {
        this.tagName = tagName;
    }

    public void rootTag(XMLEventReader reader, XMLEvent startEvent) throws XMLStreamException {
        StartElement startElement = startEvent.asStartElement();
        assertEquals(tagName, startElement.getName().getLocalPart());
        for (Iterator<Attribute> attributes = startElement.getAttributes();
             attributes.hasNext(); ) {
            Attribute attribute = attributes.next();
            if (!"".equals(attribute.getName().getNamespaceURI())) continue;//ignore
            processRootAttribute(attribute);
        }
        XMLEvent event;
        while ((event = reader.nextTag()).isStartElement()) {
            StartElement innerElement = event.asStartElement();
            processSubTag(reader, innerElement);
        }
        assertEquals(tagName, event.asEndElement().getName().getLocalPart());
    }

    protected boolean readText(XMLEventReader reader, StartElement innerElement,
                               String name,
                               Consumer<String> found) throws XMLStreamException {
        if(!name.equals(innerElement.getName().getLocalPart())) return false;
        found.accept(reader.getElementText());
        return true;
    }

    protected boolean readLong(XMLEventReader reader, StartElement innerElement,
                               String name,
                               Consumer<Long> found) throws XMLStreamException {
        if(!name.equals(innerElement.getName().getLocalPart())) return false;
        found.accept(Long.decode(reader.getElementText()));
        return true;
    }

    protected void processSubTag(XMLEventReader reader, StartElement innerElement) throws XMLStreamException {
        throw new RuntimeException("tag not supported: " + tagName + "." + innerElement.getName().getLocalPart());
    }

    protected void processRootAttribute(Attribute attribute) {
        throw new RuntimeException("Attribute not supported: " + tagName + "#" + attribute.getName().getLocalPart());
    }
}
