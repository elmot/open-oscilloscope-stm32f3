var colors = ["#226622", "#222266", "#666622", "#44FF44", "#4444FF", "#FFFF44"];
/**
 @type {CanvasRenderingContext2D}
 */
var canvasCtx = document.getElementById("canvas").getContext("2d");

function showStatus(text) {
    document.getElementById("device-info").innerHTML = text;
}

function drawData(data) {
    canvasCtx.fillStyle = "#000000";
    canvasCtx.fillRect(0, 0, canvasCtx.canvas.width, canvasCtx.canvas.height);
    for (var j = 0; j < data.length; j++) {
        var array = data[j];
        if (array == null) continue;
        canvasCtx.strokeStyle = colors[j];
        canvasCtx.beginPath();
        var zx = canvasCtx.canvas.width / array.length;
        var zy = canvasCtx.canvas.height / frameParam.h;
        //var zx = zy = 1;
        canvasCtx.moveTo(0, zy * (frameParam.h - array[1]));
        for (var i = 2; i < array.length; i++) {
            canvasCtx.lineTo(i * zx, (frameParam.h - array[i]) * zy);
        }
        canvasCtx.lineWidth = 2;
        canvasCtx.stroke();
    }
    canvasCtx.beginPath();
    var trigLevel = document.getElementById("trig.level");
    if (trigLevel.value != null) {
        var tY = canvasCtx.canvas.height * (1.0 - trigLevel.value / frameParam.h);
        canvasCtx.beginPath();
        canvasCtx.moveTo(0,tY);
        canvasCtx.lineTo(canvasCtx.canvas.width,tY);
        canvasCtx.lineWidth = 1;
        canvasCtx.strokeStyle = "#606060";
        canvasCtx.stroke();
    }
}

function setZoom() {
    var zx = document.getElementById("x.zoom").value;
    var zy = document.getElementById("y.zoom").value;
    var canvas = document.getElementById("canvas");
    canvas.width = frameParam.w * zx;
    canvas.style.width = canvas.width + "px";
    canvas.height = frameParam.h * zy;
    canvas.style.height = canvas.height + "px";
}

function scanControls() {
    var nodeList = document.querySelectorAll(".paramInput");
    for (var i = 0; i < nodeList.length; i++) {
        var elm = nodeList[i];
        setParam(elm.name, elm.value);
    }
}

document.addEventListener('DOMContentLoaded', function () {
    function _addListener(selector, event, f) {
        var list = document.querySelectorAll(selector);
        for (var i = 0; i < list.length; i++) {
            list[i].addEventListener(event, f);
        }
    }

    function setParamFromInput(event) {
        var elm = event.srcElement;
        console.log(elm.name + ":" + elm.value);//todo remove
        var nodeList = document.querySelectorAll(".input-value[for='" + elm.name + "']");
        for (var i = 0; i < nodeList.length; i++) nodeList[i].innerHTML = elm.value
        setParam(elm.name, elm.value)
    }

    function wheelSelect(event) {
        if (event.srcElement.options) {
            var idx = event.srcElement.selectedIndex;
            if (idx > 0 && event.wheelDelta > 0) idx--;
            else if (event.wheelDelta < 0 && idx + 1 < event.srcElement.options.length) idx++;
            event.srcElement.selectedIndex = idx;
            event.srcElement.dispatchEvent(new Event("change"))
        }

    }

    function wheelChange(event) {
        if (event.srcElement.value) {
            var v = event.srcElement.value - event.wheelDelta;
            if (v < event.srcElement.min) v = event.srcElement.min;
            if (v > event.srcElement.max) v = event.srcElement.max;
            event.srcElement.value = v;
            event.srcElement.dispatchEvent(new Event("change"))
        }

    }

    function pickVertical(event) {
        var elm = event.srcElement;

        function verticalPickClick(event) {
            cancelPick();
            var value = frameParam.h * (1.0 - event.offsetY / event.srcElement.offsetHeight);
            value = Math.floor(value);
            var elm = document.getElementById("trig.level");
            elm.value = value;
            elm.dispatchEvent(new Event("change"));
            console.log(event)
        }

        function cancelPick() {
            elm.classList.remove("activated");
            canvasCtx.canvas.classList.remove("aiming");
            canvasCtx.canvas.removeEventListener("click", verticalPickClick)
        }


        if (elm.classList.contains("activated")) {
            cancelPick();
        } else {
            elm.classList.add("activated");
            canvasCtx.canvas.classList.add("aiming");
            canvasCtx.canvas.addEventListener("click", verticalPickClick)
        }
    }

    function inputReset(event) {
        var elm = event.srcElement;
        var valueElement = document.getElementById(elm.getAttribute("for"));
        if (valueElement != null) {
            valueElement.value = elm.value;
            valueElement.dispatchEvent(new Event("change"))
        }
    }

    _addListener(".paramInput", "change", setParamFromInput);
    _addListener(".paramScreen", "change", setZoom);
    _addListener(".wheelSelect", "wheel", wheelSelect);
    _addListener(".vertical-picker", "click", pickVertical);
    _addListener(".inputReset", "click", inputReset);
    _addListener(".wheelChange", "wheel", wheelChange);
    setZoom();
});

