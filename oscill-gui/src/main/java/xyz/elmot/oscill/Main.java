package xyz.elmot.oscill;

import javax.usb.*;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.List;

/**
 * @author elmot Date: 19.10.15
 */

public class Main {
    public static void main(String[] args) throws UsbException {
        System.out.println("hello = ");
        UsbHub rootUsbHub = UsbHostManager.getUsbServices().getRootUsbHub();
        UsbDevice device = findDevice(rootUsbHub, (short) 0xe140, (short) 0xdf30);
        System.out.println("device = " + device);
        UsbInterface usbInterface = device.getUsbConfiguration((byte) 1).getUsbInterface((byte) 0);
        UsbEndpoint cmdEP = usbInterface.getUsbEndpoint((byte) 0x2);
        usbInterface.claim(new UsbInterfacePolicy() {
            @Override
            public boolean forceClaim(UsbInterface usbInterface) {
                return true;
            }
        });
        try {
            readConf(usbInterface);
            sendData(cmdEP);
        } finally {
            usbInterface.release();
        }
    }

    private static void sendData(UsbEndpoint cmdEP) throws UsbException {
        System.out.println("cmdEP.getType() = " + cmdEP.getType());
        System.out.println("cmdEP.getDirection() = " + cmdEP.getDirection());
        byte datablock[] = "01234567890ABCDEF01234567890ABCDEF01234567890ABCDEF01234567890ABCDEF01234567890ABCDEF01234567890ABCDEF01234567890ABCDEF01234567890ABCDEF".getBytes();
        UsbPipe usbPipe = cmdEP.getUsbPipe();
        usbPipe.open();
        try {
            usbPipe.syncSubmit(datablock);
        } finally {
            usbPipe.close();
        }
        System.out.println(datablock[0]);
    }

    private static void readConf(UsbInterface usbInterface) throws UsbException {
        byte lengthlock[] = new byte[4];
        UsbEndpoint inEp = usbInterface.getUsbEndpoint((byte) 0x81);
        UsbEndpoint outEp = usbInterface.getUsbEndpoint((byte) 0x2);
        UsbPipe usbPipe = outEp.getUsbPipe();
        usbPipe.open();
        try {
            String cmd = "GET_CONFIG";
            ByteBuffer packet = ByteBuffer.allocate(cmd.length() + 4).order(ByteOrder.LITTLE_ENDIAN);
            packet.putInt(cmd.length());
            packet.put(cmd.getBytes(StandardCharsets.US_ASCII));
            if(usbPipe.syncSubmit(packet.array()) < packet.limit()) {
                throw new RuntimeException("Command Submission Error");
            }
        } finally {
            usbPipe.close();
        }
        usbPipe = inEp.getUsbPipe();
        usbPipe.open();
        try {

            usbPipe.syncSubmit(lengthlock);
            int length = lengthlock[0] & 0xFF;
            length |= (lengthlock[1] & 0xFF) << 8;
            length |= (lengthlock[2] & 0xFF) << 16;
            length |= (lengthlock[3] & 0xFF) << 8;
            byte datablock[] = new byte[length];
            usbPipe.syncSubmit(datablock);
            System.out.println("datablock = " + new String(datablock));
        } finally {
            usbPipe.close();
        }
    }

    public static UsbDevice findDevice(UsbHub hub, short vendorId, short productId) {
        for (UsbDevice device : (List<UsbDevice>) hub.getAttachedUsbDevices()) {
            UsbDeviceDescriptor desc = device.getUsbDeviceDescriptor();
            if (desc.idVendor() == vendorId && desc.idProduct() == productId) return device;
            if (device.isUsbHub()) {
                device = findDevice((UsbHub) device, vendorId, productId);
                if (device != null) return device;
            }
        }
        return null;
    }
}
