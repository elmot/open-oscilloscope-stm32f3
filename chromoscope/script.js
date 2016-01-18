var usbConnection = null;

/**
 @type {CanvasRenderingContext2D}
 */
var canvasCtx = document.getElementById("canvas").getContext("2d");

var deviceInfo = document.getElementById("device-info");
function onDeviceFound(devices) {
    this.devices = devices;
    if (devices) {
        if (devices.length > 0) {
            chrome.usb.openDevice(devices[0], function (connection) {
                if (connection) {
                    usbConnection = connection;
                    deviceInfo.innerHTML = "Device opened.";
                    scheduleFrame();
                } else {
                    deviceInfo.innerHTML = "Device failed to open.";
                }
            });


        } else {
            deviceInfo.innerHTML = "Device could not be found";
        }
    } else {
        deviceInfo.innerHTML = "Permission denied.";
    }
}
function drawData(array) {
    canvasCtx.beginPath();
    canvasCtx.fillStyle = "#000000";
    canvasCtx.fillRect(0,0, canvasCtx.canvas.width, canvasCtx.canvas.height );
    //var zx = canvasCtx.canvas.width / array.length;
    //var zy = canvasCtx.canvas.height / 2048;
    var zx = zy = 1;
    canvasCtx.moveTo(0,zy * array[0]);
    for(var i = 1; i < array.length; i++)
    {
        canvasCtx.lineTo(i * zx , array[i] * zy);
    }
    canvasCtx.strokeStyle = "#FFFFFF";
    canvasCtx.stroke();

}


function runFrame () {
    chrome.usb.claimInterface(usbConnection, 0, function () {
        if (chrome.runtime.lastError) {
            console.error(chrome.runtime.lastError);
            return;
        }
        chrome.usb.bulkTransfer(usbConnection, {
            "direction": "out",
            "endpoint": 2,
            "data": new Uint8Array([4, 8, 15, 16]).buffer
        }, function (transferResult) {
            chrome.usb.bulkTransfer(usbConnection, {
                "direction": "in",
                "endpoint": 129,
                "length": 4096
            }, function (transferResult) {
                var l = transferResult.data ? transferResult.data.byteLength : -1;
                //console.log("Received data " + l +" bytes", transferResult);
                chrome.usb.releaseInterface(usbConnection, 0, function () {
                    if (chrome.runtime.lastError)
                        console.error(chrome.runtime.lastError);
                });
                drawData(new Uint16Array(transferResult.data));
            });

        });
    });


}

function scheduleFrame() {
    runFrame();
    window.setTimeout(scheduleFrame,10);
}

chrome.usb.getDevices({"vendorId": 57664, "productId": 57136}, onDeviceFound);
