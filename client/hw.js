var frameParam = {w: 1400, h: 4096, vertGridN: 14, horGridN: 10};

/**
 @type {CanvasRenderingContext2D}
 */


//var data = [null, null, null, null, null, null];

let port = {path: "/dev/ttyACM0", received: ""};

function convertArrayBufferToString(buf) {
    let bufView = new Uint8Array(buf);
    let encodedString = String.fromCharCode.apply(null, bufView);
    return decodeURIComponent(encodedString);
}

function setParam(name, value) {
    osc.sendCommand(name + "=" + value);
}

function initHW() {
    chrome.serial.getDevices(function (ports) {
        for (let i = 0; i < ports.length; i++) {
            console.log(ports[i].path + "; " + ports[i].displayName);
        }
    });
    const startString = "FRAME\n";
    const endString = "\nEND\n";
    let onReceiveCallback = function (info) {
            if (info.connectionId === port.connectionId && info.data) {
                port.received += convertArrayBufferToString(info.data);
                let endIndex = port.received.indexOf(endString);
                if (endIndex >= 0) {
                    let frameIndex = port.received.indexOf(startString);
                    if (frameIndex >= 0 && frameIndex < endIndex) {
                        let frameText = port.received.substring(frameIndex + startString.length, endIndex);
                        //frameText = frameText.split(/\n/);
                        let data = [];
                        for (let i = 0; i < frameText.length; i += 3) {
                            data.push(parseInt(frameText.substr(i, 3), 16))
                        }
                        drawData([data])
                    }
                    port.received = port.received.substr(endIndex + endString.length);
                }
            }
        }
    ;
    chrome.serial.onReceive.addListener(onReceiveCallback);
    chrome.serial.connect(port.path, {bitrate: 2000000}, function (connectionInfo) {
        // The serial port has been opened. Save its id to use later.
        port.connectionId = connectionInfo.connectionId;
        // Do whatever you need to do with the opened port.
    });
}

function d() {
    document.getElementById("trig.level").value = 200
    let d = [[], []];
    let dx = Math.random();
    for (let i = 0; i < 1400; i++) {
        d[1][i] = 4000 * Math.sin(dx / 20 + i / 200);
        d[0][i] = 4000 * Math.sin(dx + i / 250);
    }
    drawData(d);
}

