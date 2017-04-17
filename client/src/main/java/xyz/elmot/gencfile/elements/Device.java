package xyz.elmot.gencfile.elements;

import javax.xml.namespace.QName;
import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.Attribute;
import javax.xml.stream.events.StartElement;
import javax.xml.stream.events.XMLEvent;
import java.io.File;
import java.io.IOException;
import java.io.Serializable;
import java.util.LinkedHashMap;
import java.util.Map;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

/**
 * (c) elmot on 16.4.2017.
 */
@SuppressWarnings("WeakerAccess")
public class Device extends NamedElement {

    public static final String PERIPHERALS = "peripherals";
    private String version;
    protected Map<String, Peripheral> peripherals = new LinkedHashMap<>();
    protected Map<String, Map<String, Peripheral>> peripheralGroups = new LinkedHashMap<>();
    private final Defaults defaults = new Defaults();

    public static class Defaults implements Serializable {
        int addressUnitBits;
        int width;
        Integer size;
        Long resetValue;
        Long resetMask;
    }

    public Device() {
        super("device");
    }

    @Override
    protected void processSubTag(XMLEventReader reader, StartElement innerElement) throws XMLStreamException {
        if (readText(reader, innerElement, "version", s -> this.version = s)) return;
        if (readLong(reader, innerElement, "addressUnitBits", i -> defaults.addressUnitBits = i.intValue())) return;
        if (readLong(reader, innerElement, "width", i -> defaults.width = i.intValue())) return;
        if (readLong(reader, innerElement, "size", i -> defaults.size = i.intValue())) return;
        if (readLong(reader, innerElement, "resetValue", i -> defaults.resetValue = i)) return;
        if (readLong(reader, innerElement, "resetMask", i -> defaults.resetMask = i)) return;
        if (PERIPHERALS.equals(innerElement.getName().getLocalPart())) {
            XMLEvent event;
            while ((event = reader.nextTag()).isStartElement()) {
                Peripheral peripheral;
                Attribute derivedFromName = event.asStartElement().getAttributeByName(QName.valueOf(Peripheral.DERIVED_FROM));
                if (derivedFromName != null) {
                    Peripheral derivedFrom = peripherals.get(derivedFromName.getValue());
                    peripheral = Peripheral.copyOf(derivedFrom);
                } else {
                    peripheral = new Peripheral(this);
                }
                peripheral.rootTag(reader, event);
                String name = peripheral.getName();
                peripherals.put(name, peripheral);
                peripheralGroups.computeIfAbsent(peripheral.getGroupName(),
                        s -> new LinkedHashMap<>()).put(name, peripheral);
            }
            assertEquals(PERIPHERALS, event.asEndElement().getName().getLocalPart());
            return;
        }
        super.processSubTag(reader, innerElement);
    }

    @Override
    protected void processRootAttribute(Attribute attribute) {
        if ("schemaVersion".equals(attribute.getName().getLocalPart())) return; //ignore
        super.processRootAttribute(attribute);
    }

    public Map<String, Peripheral> getPeripherals() {
        return peripherals;
    }

    public void writeDevice(File folder) throws IOException {
        assertTrue(folder.isDirectory());
        assertTrue(folder.canWrite());
        for (Map.Entry<String, Peripheral> entry : peripherals.entrySet()) {
            File file = new File(folder, entry.getKey() + ".h");
            entry.getValue().write(file, defaults);
        }
    }
}
