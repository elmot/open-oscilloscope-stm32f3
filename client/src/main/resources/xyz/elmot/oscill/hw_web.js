var frameParam = {w: 2047, h: 4096};

/**
 @type {CanvasRenderingContext2D}
 */


//var data = [null, null, null, null, null, null];


function setParam(name, value) {
    var oReq = new XMLHttpRequest();
    oReq.open("POST", "/cmd", true);
    oReq.onerror = function (oEvent) {
        document.getElementById("device-info").innerHTML = "<em>Communication error</em>";
    };
    oReq.ontimeout = function (oEvent) {
        document.getElementById("device-info").innerHTML = "<em>Communication timeout</em>";
    };

    oReq.send(name + "=" + value);
}

function requestFrame() {
    var oReq = new XMLHttpRequest();
    oReq.open("POST", "/frame", true);
    oReq.responseType = "arraybuffer";
    oReq.onload = function (oEvent) {
      var arrayBuffer = oReq.response; // Note: not oReq.responseText
      if (arrayBuffer && arrayBuffer.byteLength > 2) {
        var dView = new DataView(arrayBuffer);
        var header = dView.getUint16(0, true);

        var shortArray = new Uint16Array(arrayBuffer.byteLength / 2 - 1);
        for(var i = 0; i < shortArray.length;i++)
            shortArray[i] = dView.getUint16(i * 2 + 2, true);
        if(shortArray.length >0) {
            drawData([shortArray]);
        }
        document.getElementById("device-info").innerHTML = "";
      }
    };
    oReq.onerror = function (oEvent) {
        document.getElementById("device-info").innerHTML = "<em>Communication error</em>";
    };
    oReq.ontimeout = function (oEvent) {
        document.getElementById("device-info").innerHTML = "<em>Communication timeout</em>";
    };

    oReq.send(null);
}

setInterval(requestFrame, 250);





