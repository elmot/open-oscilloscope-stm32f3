package xyz.elmot.gencfile.elements;

import org.junit.Assert;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.StartElement;
import javax.xml.stream.events.XMLEvent;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import static org.junit.Assert.assertTrue;

/**
 * (c) elmot on 16.4.2017.
 */
@SuppressWarnings("WeakerAccess")
public class Register extends NamedElement implements Comparable<Register>, Copyable {
    public static final String FIELDS = "fields";
    private String displayName;
    private long addressOffset;
    private Integer size;
    private String access;
    private String alternateRegister;
    private long resetValue;
    private List<Field> fields = new ArrayList<>();

    public Register() {
        super("register");
    }

    @Override
    protected void processSubTag(XMLEventReader reader, StartElement innerElement) throws XMLStreamException {
        if (readText(reader, innerElement, "displayName", s -> displayName = s)) return;
        if (readLong(reader, innerElement, "addressOffset", i -> addressOffset = i)) return;
        if (readLong(reader, innerElement, "size", i -> size = i.intValue())) return;
        if (readText(reader, innerElement, "access", s -> access = s)) return;
        if (readText(reader, innerElement, "alternateRegister", s -> alternateRegister = s)) return;
        if (readLong(reader, innerElement, "resetValue", i -> resetValue = i)) return;
        if (FIELDS.equals(innerElement.asStartElement().getName().getLocalPart())) {
            XMLEvent event;
            while ((event = reader.nextTag()).isStartElement()) {
                Field field = new Field();
                field.rootTag(reader, event);
                fields.add(field);
            }
            Assert.assertEquals(FIELDS, event.asEndElement().getName().getLocalPart());
            return;
        }
        super.processSubTag(reader, innerElement);
    }

    public String getDisplayName() {
        return displayName;
    }

    public long getAddressOffset() {
        return addressOffset;
    }

    public int getSize() {
        return size;
    }

    public String getAccess() {
        return access;
    }

    public long getResetValue() {
        return resetValue;
    }

    public List<Field> getFields() {
        return fields;
    }

    public String getAlternateRegister() {
        return alternateRegister;
    }

    @Override
    public int compareTo(Register o) {
        return Long.compare(addressOffset, o.getAddressOffset());
    }

    @Override
    public void copyFrom(Copyable o) {
        super.copyFrom(o);
        Register another = (Register) o;
        displayName = another.displayName;
        addressOffset = another.addressOffset;
        alternateRegister = another.alternateRegister;
        size = another.size;
        access = another.access;
        resetValue = another.resetValue;
        fields = copy(another.getFields());
    }

    public long write(long currentAddressOffset, Device.Defaults defaults, PrintWriter writer) {
        int size = this.size == null ? defaults.size : this.size;
        int sizeBytes = size / 8;
        if (currentAddressOffset > this.addressOffset) {
            //TODO generate unions
            System.err.printf("WARNING!!! Overlapping register: %s(%s). Skipping.\n", name, alternateRegister);
            return currentAddressOffset;
        }
        Field.writeUnused(writer, (int) ((this.addressOffset - currentAddressOffset) * 8));

        writer.printf("// %s\n struct {\n", description);
        Collections.sort(fields);
        int fieldOffset = 0;
        for (Field field : fields) {
            fieldOffset = field.write(fieldOffset, writer);
        }
        assertTrue("Extra field size!", fieldOffset <= size);
        Field.writeUnused(writer, size - fieldOffset);
        writer.printf("} %s;\n", name);


        return this.addressOffset + sizeBytes;
    }
}