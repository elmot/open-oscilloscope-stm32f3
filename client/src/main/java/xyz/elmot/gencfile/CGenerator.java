package xyz.elmot.gencfile;

import xyz.elmot.gencfile.elements.Device;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.XMLEvent;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;

/**
 * (c) elmot on 16.4.2017.
 */
public class CGenerator {
    public static void main(String[] args) throws IOException, XMLStreamException {
        try (InputStream stream = CGenerator.class.getResourceAsStream("/xyz/elmot/gencfile/STM32F303xE.svd.xml")
        ) {
            XMLEventReader xmlEventReader = XMLInputFactory.newFactory().createXMLEventReader(stream);
            XMLEvent xmlEvent = xmlEventReader.nextTag();
            Device device = new Device();
            device.rootTag(xmlEventReader,xmlEvent);
            File folder = new File("/home/elmot/projects/open-oscilloscope-stm32f3/SVD_Inc");
            folder.mkdirs();
            device.writeDevice(folder);
        }
    }

}
