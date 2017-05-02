package xyz.elmot.gencfile;

import xyz.elmot.gencfile.elements.Device;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.XMLEvent;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.util.function.Supplier;

/**
 * (c) elmot on 16.4.2017.
 */
public class CGeneratorTest {
    public static void main(String[] args) throws IOException, XMLStreamException {
        CGenerator.runParser(() -> CGeneratorTest.class.getResourceAsStream("/xyz/elmot/gencfile/STM32F303xE.svd.xml"), "/home/elmot/projects/open-oscilloscope-stm32f3/SVD_Inc");
    }


}
