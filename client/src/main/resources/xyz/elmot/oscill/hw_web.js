var frameParam = {w: 2047, h: 4096};

/**
 @type {CanvasRenderingContext2D}
 */


//var data = [null, null, null, null, null, null];


function setParam(name, value) {
    console.log("Parameters setting is not implemented! " + name + ": " + value);
}

function requestFrame() {
    var oReq = new XMLHttpRequest();
    oReq.open("POST", "/cmd", true);
    oReq.responseType = "arraybuffer";
    oReq.onload = function (oEvent) {
      var arrayBuffer = oReq.response; // Note: not oReq.responseText
      if (arrayBuffer) {
        var shortArray = new Uint16Array(arrayBuffer);
        if(shortArray.length >0) {
            drawData([shortArray]);
        }
      }
        requestFrame();
    };

    oReq.send(null);
}

setInterval(requestFrame, 20);





