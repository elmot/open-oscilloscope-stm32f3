package xyz.elmot.gencfile.elements;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.StartElement;

/**
 * (c) elmot on 16.4.2017.
 */
public abstract class  NamedElement extends CommonElement implements Copyable{
    public NamedElement(String tagName) {
        super(tagName);
    }

    protected String name;
    protected String description;

    @Override
    protected void processSubTag(XMLEventReader reader, StartElement innerElement) throws XMLStreamException {
        if (readText(reader, innerElement, "name", s -> this.name = s)) return;
        if (readText(reader, innerElement, "description", s -> this.description = s)) return;
        super.processSubTag(reader, innerElement);
    }

    public String getName() {
        return name;
    }

    public String getDescription() {
        return description;
    }

    @Override
    public void copyFrom(Copyable o) {
        name = ((NamedElement)o).name;
        description = ((NamedElement)o).description;
    }
}
