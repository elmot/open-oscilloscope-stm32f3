var frameParam = {w: 2047, h: 4096};
var oReq = new XMLHttpRequest();
oReq.onerror = function () {
    showStatus("<em>Communication error</em>");
};
oReq.onabort = function () {
    showStatus("<em>Communication broken</em>");
};
oReq.ontimeout = function () {
    showStatus("<em>Communication timeout</em>");
};

var data;
var cmdQueue = [];
function initData() {
    data = [null, null/*todo channels, null, null, null, null*/];
}
initData();

function setParam(name, value) {
    cmdQueue.unshift(name + "=" + value);
}

function requestFrame() {
    if (oReq.readyState !== 0 && oReq.readyState !== 4) return;
    var cmd = cmdQueue.pop() || null;
    if (cmd !== null) {
        oReq.onload = function () {
            initData();
            showStatus();
            var lines = oReq.response.slice(2).match(/[^\r\n]+/g);

            for(var i =0; i < lines.length;i++) {
                var pair = lines[i].split("=");
                updateGuiControl(pair[0], pair[1]);
            }
        };
        oReq.open("POST", "/cmd", true);
        oReq.responseType = "text";
        oReq.send(cmd);
        return;
    }

    oReq.onload = function () {
        var arrayBuffer = oReq.response; // Note: not oReq.responseText
        if (arrayBuffer && arrayBuffer.byteLength > 2) {
            var dView = new DataView(arrayBuffer);
            dView.getUint16(0, true);//Signature todo take in account
            var header = dView.getUint16(2, true);
            var shortArray = new Uint16Array(arrayBuffer.byteLength / 2 - 2);
            for (var i = 0; i < shortArray.length; i++)
                shortArray[i] = dView.getUint16(i * 2 + 4, true);
            if (shortArray.length > 0) {
                if ((header & 0x4000) !== 0) {
                    data = [null, shortArray]
                } else {
                    data[0] = shortArray
                }
                drawData(data);
            }
            showStatus("");
        }
    };
    oReq.open("POST", "/frame", true);
    oReq.responseType = "arraybuffer";
    oReq.send("");
}

setInterval(requestFrame, 10);
