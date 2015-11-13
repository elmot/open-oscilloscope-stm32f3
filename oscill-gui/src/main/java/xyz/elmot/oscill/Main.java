package xyz.elmot.oscill;

import javax.usb.*;
import java.util.List;

/**
 * @author elmot
 *         Date: 19.10.15
 */

public class Main {
    public static void main(String[] args) throws UsbException {
        System.out.println("hello = ");
        UsbHub rootUsbHub = UsbHostManager.getUsbServices().getRootUsbHub();
        UsbDevice device = findDevice(rootUsbHub, (short) 0xe140, (short) 0xdf30);
        System.out.println("device = " + device);
        UsbInterface usbInterface = device.getUsbConfiguration((byte) 1).getUsbInterface((byte) 0);
        UsbEndpoint cmdEP = usbInterface.getUsbEndpoint((byte) 0x3);
        usbInterface.claim(new UsbInterfacePolicy() {
            @Override
            public boolean forceClaim(UsbInterface usbInterface) {
                return true;
            }
        });
        try {
            System.out.println("cmdEP.getType() = " + cmdEP.getType());
            System.out.println("cmdEP.getDirection() = " + cmdEP.getDirection());
            byte datablock[]="01234567890ABCDEF01234567890ABCDEF01234567890ABCDEF01234567890ABCDEF01234567890ABCDEF01234567890ABCDEF01234567890ABCDEF01234567890ABCDEF".getBytes();
            UsbPipe usbPipe = cmdEP.getUsbPipe();
            usbPipe.open();
            try {
                usbPipe.syncSubmit(datablock);
            } finally {
                usbPipe.close();
            }
            System.out.println(datablock[0]);
        } finally {
            usbInterface.release();
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
