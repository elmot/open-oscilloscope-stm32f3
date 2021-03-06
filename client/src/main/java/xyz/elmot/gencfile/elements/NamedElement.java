package xyz.elmot.gencfile.elements;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.StartElement;

/**
 * (c) elmot on 16.4.2017.
 */
public abstract class  NamedElement extends CommonElement{
    public NamedElement(String tagName) {
        super(tagName);
    }

    protected String name;
    protected String description;

    @Override
    protected void processSubTag(XMLEventReader reader, StartElement innerElement) throws XMLStreamException {
        if (readText(reader, innerElement, "name", s -> this.name = s)) return;
        if (readText(reader, innerElement, "description", s -> this.description = normalize(s))) return;
        super.processSubTag(reader, innerElement);
    }

    private String normalize(String s) {
        return s.replace('\n', ' ').replace('\r', ' ');
    }

    public String getName() {
        return name;
    }

    public String getDescription() {
        return description;
    }

}
