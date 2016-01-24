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
        if (array == null) continue;
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
        console.log(elm.name + ":" +  elm.value);//todo remove
        var nodeList = document.querySelectorAll(".input-value[for='" + elm.name + "']")
        for(var i = 0; i < nodeList.length; i++) nodeList[i].innerHTML = elm.value
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
            if(v < event.srcElement.min) v = event.srcElement.min;
            if(v > event.srcElement.max) v = event.srcElement.max;
            event.srcElement.value = v;
            event.srcElement.dispatchEvent(new Event("change"))
        }

    }

    function pickVertical(event) {
        var elm = event.srcElement;

        function verticalPickClick(event) {
            cancelPick();
            console.log(event)
        }

        function cancelPick() {
            elm.classList.remove("pressed");
            canvasCtx.canvas.classList.remove("aiming");
            canvasCtx.canvas.removeEventListener("click", verticalPickClick)
        }


        if (elm.classList.contains("pressed")) {
            cancelPick();
        } else {
            elm.classList.add("pressed");
            canvasCtx.canvas.classList.add("aiming");
            canvasCtx.canvas.addEventListener("click", verticalPickClick)
        }
    }

    function inputReset(event) {
        var elm = event.srcElement;
        var valueElement = document.getElementById(elm.getAttribute("for"));
        if(valueElement != null)
        {
            valueElement.value = elm.value;
            valueElement.dispatchEvent(new Event("change"))
        }
    }

    _addListener(".paramInput", "change", setParamFromInput);
    _addListener(".wheelSelect", "wheel", wheelSelect);
    _addListener(".vertical-picker", "click", pickVertical);
    _addListener(".inputReset", "click", inputReset);
    _addListener(".wheelChange", "wheel", wheelChange);
    initialDeviceDetect();
});

