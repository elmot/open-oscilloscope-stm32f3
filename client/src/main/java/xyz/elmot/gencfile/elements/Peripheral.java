package xyz.elmot.gencfile.elements;

import org.junit.Assert;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.Attribute;
import javax.xml.stream.events.StartElement;
import javax.xml.stream.events.XMLEvent;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * (c) elmot on 16.4.2017.
 */
public class Peripheral extends NamedElement implements Copyable {
    private final Device parent;
    private String groupName;
    private long baseAddress;
    private List<AddressBlock> addressBlocks = new ArrayList<>();
    private List<Register> registers = new ArrayList<>();
    private Interrupt interrupt;

    public Peripheral(Device parent) {
        super("peripheral");
        this.parent = parent;
    }

    public String getGroupName() {
        return groupName;
    }

    @Override
    protected void processSubTag(XMLEventReader reader, StartElement innerElement) throws XMLStreamException {
        if (readText(reader, innerElement, "groupName", s -> this.groupName = s)) return;
        if (readLong(reader, innerElement, "baseAddress", i -> baseAddress = i)) return;
        switch (innerElement.getName().getLocalPart()) {
            case "addressBlock":
                AddressBlock addressBlock = new AddressBlock();
                addressBlock.rootTag(reader, innerElement);
                addressBlocks.add(addressBlock);
                return;
            case "interrupt":
                interrupt = new Interrupt();
                interrupt.rootTag(reader, innerElement);
                return;
            case "registers":
                readRegisters(reader);
                return;

        }
        super.processSubTag(reader, innerElement);
    }

    private boolean readRegisters(XMLEventReader reader) throws XMLStreamException {
        XMLEvent event;
        while ((event = reader.nextTag()).isStartElement()) {
            Register register = new Register();
            register.rootTag(reader, event);
            registers.add(register);
        }
        Assert.assertEquals("registers", event.asEndElement().getName().getLocalPart());
        return true;
    }

    @Override
    protected void processRootAttribute(Attribute attribute) {
        if ("derivedFrom".equals(attribute.getName().getLocalPart())) {
            Peripheral derivedFrom = parent.getPeripherals().get(attribute.getValue());
            Assert.assertNotNull(derivedFrom);
            copyFrom(derivedFrom);
            return;
        }
        super.processRootAttribute(attribute);
    }

    public Device getParent() {
        return parent;
    }

    public long getBaseAddress() {
        return baseAddress;
    }

    public List<AddressBlock> getAddressBlocks() {
        return addressBlocks;
    }

    public List<Register> getRegisters() {
        return registers;
    }

    @Override
    public void copyFrom(Copyable o) {
        super.copyFrom(o);
        Peripheral another = (Peripheral) o;
        groupName = another.groupName;
        baseAddress = another.baseAddress;
        addressBlocks = copy(another.addressBlocks);
        registers = copy(another.registers);
    }

    public void write(File file, Device.Defaults defaults) throws IOException {
        try (FileOutputStream stream = new FileOutputStream(file);
             PrintWriter writer = new PrintWriter(new OutputStreamWriter(stream, StandardCharsets.US_ASCII))) {
            writer.printf("// %s\n extern struct {\n",description);

            Collections.sort(registers);
            long offsetAddress = 0;
            for (Register register : registers) {
                offsetAddress = register.write(offsetAddress, defaults, writer);
            }
            writer.printf("} SVD_%s __attribute__ ((packed));\nasm(\".equ SVD_%s, 0x%08x\");\n", name, name, baseAddress);
        }
    }
}
