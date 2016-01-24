var usbConnection = null;
var openDevice = null;
var cmdQueue = [];
var frameParam = {w:2047,h:4096};
/**
 @type {CanvasRenderingContext2D}
 */

var deviceInfo = document.getElementById("device-info");

function registerDevice(device) {
    if (openDevice != null) return;
    chrome.usb.openDevice(device, function (connection) {
        if (connection) {
            openDevice = device;
            usbConnection = connection;
            showStatus("Device opened: " + openDevice.productName + "(" + openDevice.manufacturerName + ") #" + openDevice.serialNumber);
            scanControls();
            runFrame();
        } else {
            showStatus("Device failed to open.");
        }
    });
}
function onDeviceFound(devices) {
    if (devices) {
        if (devices.length > 0) {
            registerDevice(devices[0]);
        } else {
            showStatus("Device not connected");
        }
    } else {
        showStatus("Permission denied.");
    }
}
var data = [null,null,null,null,null,null];

function runFrame() {

    function startAllFrameTransfer() {
        startFrameTransfer(0);
    }

    function startFrameTransfer(index) {
        chrome.usb.bulkTransfer(usbConnection, {
            "direction": "out",
            "endpoint": 2,
            "data": new Uint8Array(encoder.encode("FRAME" + String.fromCharCode(index + 65)).buffer).buffer
        }, function (transferResult) {//todo check transfer result for errors.
            chrome.usb.bulkTransfer(usbConnection, {
                "direction": "in",
                "endpoint": 129,
                "length": 4096
            }, function (transferResult) {
                if (index < 3) {
                    var array = new Uint16Array(transferResult.data);
                    var idx = index + (array[0] > 0x7777 ? 3 : 0);
                    data[idx] = array;
                    startFrameTransfer(index + 1);
                } else {
                    chrome.usb.releaseInterface(usbConnection, 0, function () {
                        if (chrome.runtime.lastError)
                            console.warn(chrome.runtime.lastError);
                    });
                    drawData(data);

                    frameHandler = window.setTimeout(runFrame, 15);
                }
            });
        });
    }

    function commandTransfer(transferResult) {
        if (cmdQueue.length > 0) {
            chrome.usb.bulkTransfer(usbConnection, {
                "direction": "out",
                "endpoint": 2,
                "data": encoder.encode(cmdQueue.pop()).buffer
            }, commandTransfer);
            for (var i = 0; i < data.length; i++) {
                data[i] = null;
            }
        } else {
            startAllFrameTransfer();
        }
    }

    chrome.usb.claimInterface(usbConnection, 0, function () {
        if (chrome.runtime.lastError) {
            console.warn(chrome.runtime.lastError);
            return;
        }

        commandTransfer();
    });


}

function setParamFromInput(event) {
    var elm = event.srcElement;
    setParam(elm.name, elm.value)
}
function setParam(name, value) {
    cmdQueue.push(name + "=" + value)
}

chrome.usb.onDeviceRemoved.addListener(function (device) {
    if (device.device == openDevice.device) {
        if (frameHandler != null) window.clearTimeout(frameHandler);
        openDevice = null;
        chrome.usb.closeDevice(usbConnection);
        showStatus("Device disconnected");
    }
});

chrome.usb.onDeviceAdded.addListener(registerDevice);

function initialDeviceDetect() {
    chrome.usb.getDevices({"vendorId": 57664, "productId": 57136}, onDeviceFound);
}



