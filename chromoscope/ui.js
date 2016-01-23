var encoder = new TextEncoder();
var colors = ["#44FF44", "#4444FF", "#FFFF44", "#44FF44", "#4444FF", "#FFFF44" ];
/**
 @type {CanvasRenderingContext2D}
 */
var canvasCtx = document.getElementById("canvas").getContext("2d");

function showStatus(text) {
    deviceInfo.innerHTML = text;
}

function drawData(data) {
    canvasCtx.fillStyle = "#000000";
    canvasCtx.fillRect(0, 0, canvasCtx.canvas.width, canvasCtx.canvas.height);
    for (var j = 0; j < data.length; j++) {
        var array = data[j];
        if(array == null) continue;
        canvasCtx.strokeStyle = colors[j];
        canvasCtx.beginPath();
        var zx = canvasCtx.canvas.width / array.length;
        var zy = canvasCtx.canvas.height / 4096;
        //var zx = zy = 1;
        canvasCtx.moveTo(0, zy * array[1]);
        for (var i = 2; i < array.length; i++) {
            canvasCtx.lineTo(i * zx, array[i] * zy);
        }
        canvasCtx.lineWidth = array[0] > 0x777 ? 3 : 1.4;
        canvasCtx.stroke();
    }
}

function setParamFromInput(event) {
    var elm = event.srcElement;
    setParam(elm.name, elm.value)
}

function wheelSelect(event) {
    if (event.srcElement.options) {
        var idx = event.srcElement.selectedIndex;
        if (idx > 0 && event.wheelDelta < 0) idx--;
        else if (event.wheelDelta > 0 && idx + 1 < event.srcElement.options.length) idx++;
        event.srcElement.selectedIndex = idx;
    }
    setParamFromInput(event)
}

function scanControls() {
    var nodeList = document.querySelectorAll(".paramInput");
    for (var i = 0; i < nodeList.length; i++) {
        var elm = nodeList[i];
        setParam(elm.name, elm.value);
    }
}

document.addEventListener('DOMContentLoaded', function () {
    var nodeList = document.querySelectorAll(".paramInput");
    for (var i = 0; i < nodeList.length; i++) {
        nodeList[i].addEventListener("change", setParamFromInput);
    }
    nodeList = document.querySelectorAll(".scrollSelect");
    for (i = 0; i < nodeList.length; i++) {
        nodeList[i].addEventListener("wheel", wheelSelect);
    }
    initialDeviceDetect();
});

