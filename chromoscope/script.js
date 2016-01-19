var usbConnection = null;
var openDevice = null;
var cmdQueue = [];
var encoder = new TextEncoder();
/**
 @type {CanvasRenderingContext2D}
 */
var canvasCtx = document.getElementById("canvas").getContext("2d");

var deviceInfo = document.getElementById("device-info");
function showStatus(text) {
    deviceInfo.innerHTML = text;
}
function registerDevice(device) {
    if (openDevice != null) return;
    chrome.usb.openDevice(device, function (connection) {
        if (connection) {
            openDevice = device;
            usbConnection = connection;
            showStatus("Device opened: " + openDevice.productName + "(" + openDevice.manufacturerName + ") #" + openDevice.serialNumber);
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
function drawData(array) {
    canvasCtx.beginPath();
    var zx = canvasCtx.canvas.width / array.length;
    var zy = canvasCtx.canvas.height / 4096;
    //var zx = zy = 1;
    canvasCtx.moveTo(0, zy * array[0]);
    for (var i = 1; i < array.length; i++) {
        canvasCtx.lineTo(i * zx, array[i] * zy);
    }
    canvasCtx.strokeStyle = "#FFFFFF";
    canvasCtx.fillStyle = "#000000";
    canvasCtx.fillRect(0, 0, canvasCtx.canvas.width, canvasCtx.canvas.height);
    canvasCtx.stroke();

}


function runFrame() {
    function startFrameTransfer() {
        chrome.usb.bulkTransfer(usbConnection, {
            "direction": "out",
            "endpoint": 2,
            "data": new Uint8Array(encoder.encode("FRAME").buffer).buffer
        }, function (transferResult) {//todo check transfer result for errors.
            chrome.usb.bulkTransfer(usbConnection, {
                "direction": "in",
                "endpoint": 129,
                "length": 4096
            }, function (transferResult) {
                chrome.usb.releaseInterface(usbConnection, 0, function () {
                    if (chrome.runtime.lastError)
                        console.warn(chrome.runtime.lastError);
                });
                drawData(new Uint16Array(transferResult.data));
                frameHandler = window.setTimeout(runFrame, 15);
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
        } else {
            startFrameTransfer();
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
    console.log(name + ": " + value)
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

chrome.usb.getDevices({"vendorId": 57664, "productId": 57136}, onDeviceFound);


document.addEventListener('DOMContentLoaded', function () {
    var nodeList = document.querySelectorAll(".paramInput");
    for (var i = 0; i < nodeList.length; i++) {
        nodeList[i].addEventListener("click", setParamFromInput);
    }
});

