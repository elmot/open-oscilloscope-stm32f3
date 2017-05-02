package xyz.elmot.gencfile;

import xyz.elmot.gencfile.elements.Device;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.XMLEvent;
import java.io.*;
import java.util.function.Supplier;

/**
 * (c) elmot on 16.4.2017.
 */
public class CGenerator {
    public static void main(String[] args) throws IOException, XMLStreamException {
        runParser(() -> {
            try {
                return new FileInputStream(args[0]);
            } catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }
        }, args[1]);
    }

    public static void runParser(Supplier<InputStream> src, String targetFolder) throws IOException, XMLStreamException {
        try (InputStream stream = src.get()) {
            XMLEventReader xmlEventReader = XMLInputFactory.newFactory().createXMLEventReader(stream);
            XMLEvent xmlEvent = xmlEventReader.nextTag();
            Device device = new Device();
            device.rootTag(xmlEventReader, xmlEvent);
            File folder = new File(targetFolder);
            folder.mkdirs();
            device.writeDevice(folder);
        }
    }

}
