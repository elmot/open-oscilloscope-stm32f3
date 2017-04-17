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
import java.util.stream.Collectors;

/**
 * (c) elmot on 16.4.2017.
 */
public class Peripheral extends NamedElement {
    public static final String DERIVED_FROM = "derivedFrom";
    private transient Device parent;
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
        if (DERIVED_FROM.equals(attribute.getName().getLocalPart())) {
            return;//already processed
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

    public void write(File file, Device.Defaults defaults) throws IOException {
        try (FileOutputStream stream = new FileOutputStream(file);
             PrintWriter writer = new PrintWriter(new OutputStreamWriter(stream, StandardCharsets.US_ASCII))) {
            writer.printf("// %s\n extern struct {\n", description);

            Collections.sort(registers);
            long offsetAddress = 0;
            List<Register> overlappings = new ArrayList<>();
            for (int i = 0; i < registers.size(); i++) {
                Register register = registers.get(i);
                if (!overlappings.isEmpty()
                        && overlappings.get(0).getAddressOffset() != register.getAddressOffset()) {
                    offsetAddress = writeRegisterGroup(offsetAddress, overlappings, defaults, writer);
                    overlappings.clear();
                }
                overlappings.add(register);
            }
            writeRegisterGroup(offsetAddress, overlappings, defaults, writer);
            writer.printf("} SVD_%s;\nasm(\".equ SVD_%s, 0x%08x\");\n", name, name, baseAddress);
        }
    }

    private long writeRegisterGroup(long offsetAddress, List<Register> overlappings, Device.Defaults defaults, PrintWriter writer) {
        switch (overlappings.size()) {
            case 0:
                return offsetAddress;
            case 1:
                return overlappings.get(0).write(offsetAddress, defaults, writer);

        }
        long newOffsetAddress = offsetAddress;
        writer.println("  union {");
        for (Register overlapping : overlappings) {
            newOffsetAddress = Math.max(offsetAddress, overlapping.write(offsetAddress, defaults, writer));
        }
        String name = overlappings.stream().map(Register::getName).collect(Collectors.joining("_"));
        writer.printf("  } %s;\n", name);
        return newOffsetAddress;
    }

    public static Peripheral copyOf(Peripheral derivedFrom) {
        try (ByteArrayOutputStream baos = new ByteArrayOutputStream();
             ObjectOutputStream objectOutputStream = new ObjectOutputStream(baos)) {
            objectOutputStream.writeObject(derivedFrom);
            objectOutputStream.close();
            try (ObjectInputStream objectInputStream = new ObjectInputStream(new ByteArrayInputStream(baos.toByteArray()))) {
                Peripheral peripheral = (Peripheral) objectInputStream.readObject();
                peripheral.parent = derivedFrom.parent;
                return peripheral;
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
