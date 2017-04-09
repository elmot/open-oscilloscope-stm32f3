var colors = ["#4c4", "#8f8", "#44c", "#88f", "#cc4", "#ff8"];
var _e = function (id) {
    return document.getElementById(id)
};
var _et = function (id,text) {
    _e(id).innerHTML = text;
};

var disp = {
    a: _e("canvasa"),
    /**
     @type {CanvasRenderingContext2D}
     */
    aCtx: _e("canvasa").getContext("2d"),
    b: _e("canvasb"),
    /**
     @type {CanvasRenderingContext2D}
     */
    bCtx: _e("canvasb").getContext("2d"),
    c: _e("canvasc"),
    /**
     @type {CanvasRenderingContext2D}
     */
    cCtx: _e("canvasc").getContext("2d"),

    init: function () {
        this.f = document.createElement("canvas");
        this.fCtx = this.f.getContext("2d");
    },

    setZoom: function (zx, zy) {
        var w = Math.round(frameParam.w * zx);
        var h = Math.round(frameParam.h * zy);
        [this.a, this.b, this.c, this.f].map(function (canvas) {
            canvas.width = w;
            canvas.style.width = w + "px";
            canvas.height = h + 20;
            canvas.style.height = (h + 20) + "px";
        });
//        this.aCtx.globalAlpha = 0.3;
        this.aCtx.setLineDash([3, 17]);
        this.aCtx.strokeStyle = "#080";
        this.aCtx.lineWidth = 1;
        this.aCtx.beginPath();
        for (var i = 1; i < frameParam.horGridN; i++) {
            var y = Math.round(h * i / frameParam.horGridN);
            this.aCtx.moveTo(0, y);
            this.aCtx.lineTo(w, y);
        }
        for (i = 1; i < frameParam.vertGridN; i++) {
            var x = Math.round(w * i / frameParam.vertGridN);
            this.aCtx.moveTo(x, 0);
            this.aCtx.lineTo(x, h);
        }
        this.aCtx.stroke();

        this.aCtx.setLineDash([]);
        this.aCtx.beginPath();
        this.aCtx.strokeStyle = "#FFF";
        this.aCtx.moveTo(0, h + 1);
        this.aCtx.lineTo(w, h + 1);
        this.aCtx.stroke();

        this.w = w;
        this.h = h;
    }
};


function showStatus(status) {
    _et("device-info", status || "");
}

function drawData(data) {
    disp.bCtx.clearRect(0, 0, disp.w, disp.h);

    for (var j = 0; j < data.length; j++) {
        var array = data[j] || null;
        if (array === null) continue;
        disp.bCtx.lineWidth = 2;
        disp.bCtx.strokeStyle = colors[j];
        disp.bCtx.beginPath();
        var zx = disp.w/ array.length;
        var zy = disp.h / frameParam.h;
        disp.bCtx.moveTo(2, zy * (frameParam.h - array[0]));
        for (var i = 1; i < array.length; i++) {
            disp.bCtx.lineTo(i * zx, (frameParam.h - array[i]) * zy);
        }
        disp.bCtx.stroke();
    }
}
function updateOSD() {
    var selectedTiming = _e("t").options[_e("t").selectedIndex];

    var prec = selectedTiming.getAttribute("prec");
    var unit = selectedTiming.getAttribute("unit");
    var text = "T: " + prec + unit;
    _et("t-text",text);

    if (points[0] !== null && points[1] !== null) {
        text = "&Delta;T: " +
            (Math.abs(points[1].x - points[0].x) / 100.0 * parseFloat(prec)).toPrecision(4)
            + unit;
        _et("d-t-text", text);
    } else _et("d-t-text","&Delta;T: ----");

    var range = _e("s.a.range").options[_e("s.a.range").selectedIndex] || null;
    var deltaText = "&Delta;A: ----";
    if (range !== null) {
        prec = range.getAttribute("prec");
        unit = range.getAttribute("unit");
        text = "A: " + prec + unit;
        if (points[0] !== null && points[1] !== null) {
            deltaText = "&Delta;A: " +
                (Math.abs(points[1].y - points[0].y) / frameParam.h * 10.0 * parseFloat(prec))
                    .toPrecision(4) + unit;
        }

    } else {
        text = "A: ----";
    }
    _et("s-a-text", text);
    _et("d-a-text", deltaText);
    disp.cCtx.beginPath();
    disp.cCtx.strokeStyle = "#AAA";
    disp.cCtx.lineWidth = 1;
    disp.cCtx.setLineDash([5, 10]);
    for (var i = 0; i < 2; i++) {
        if (points[i] !== null) {
            var x = disp.w * points[i].x / frameParam.w;
            var y = disp.h - disp.h * points[i].y / frameParam.h;
            disp.cCtx.moveTo(x, 0);
            disp.cCtx.lineTo(x, disp.h);
            disp.cCtx.moveTo(0, y);
            disp.cCtx.lineTo(disp.w, y);
        }

    }
    disp.cCtx.stroke();
}

function drawControls() {
    disp.cCtx.clearRect(0, 0, disp.w, disp.h);
    disp.cCtx.setLineDash([15, 5]);
    var trigLevel = _e("trig.level");
    if (trigLevel.value !== null && trigLevel.value !== "") {
        var tY = disp.h * (1.0 - trigLevel.value / frameParam.h);
        disp.cCtx.beginPath();
        disp.cCtx.moveTo(0, tY);
        disp.cCtx.lineTo(disp.w, tY);
        disp.cCtx.lineWidth = 1;
        disp.cCtx.strokeStyle = "#999";
        disp.cCtx.stroke();
    }
    updateOSD();
}

function setZoom() {
    var zx = _e("x.zoom").value;
    var zy = _e("y.zoom").value;
    disp.setZoom(zx, zy);
    drawControls();
}

function scanControls() {
    var nodeList = document.querySelectorAll(".paramInput");
    for (var i = 0; i < nodeList.length; i++) {
        var elm = nodeList[i];
        setParam(elm.name, elm.value);
    }
}

function updateExtVisuals(elm) {
    var nodeList = document.querySelectorAll(".input-value[for='" + elm.name + "']");
    for (var i = 0; i < nodeList.length; i++) nodeList[i].innerHTML = elm.value
    updateOSD();
}
document.addEventListener('DOMContentLoaded', function () {
    function _addListener(selector, event, f) {
        var list = document.querySelectorAll(selector);
        for (var i = 0; i < list.length; i++) {
            list[i].addEventListener(event, f);
        }
    }

    function setParamFromInput(event) {
        var elm = event.target;
        updateExtVisuals(elm);
        setParam(elm.name, elm.value)
    }

    function wheelSelect(event) {
        if (event.target.options) {
            var idx = event.target.selectedIndex;
            var delta = event.deltaX + event.deltaY;
            if (idx > 0 && delta > 0) idx--;
            else if (delta < 0 && idx + 1 < event.target.options.length) idx++;
            event.target.selectedIndex = idx;
            event.target.dispatchEvent(new Event("change"))
        }

    }

    function wheelChange(event) {
        if (event.target.value) {
            var delta = event.deltaX + event.deltaY;
            if (event.deltaMode === 0) delta = delta / 10;
            var v = event.target.value - delta;
            if (v < event.target.min) v = event.target.min;
            if (v > event.target.max) v = event.target.max;
            event.target.value = v;
            event.target.dispatchEvent(new Event("change"))
        }

    }


    function pickClick(event) {
        var valueY = frameParam.h * (1.0 - event.offsetY / disp.h);
        valueY = Math.max(0, Math.floor(valueY));

        var valueX = frameParam.w * (event.offsetX / disp.w);
        valueX = Math.max(0, Math.floor(valueX));

        var activatedButtons = document.getElementsByClassName("button-activated");
        if (activatedButtons.length === 0) return;
        switch (activatedButtons[0].id) {
            case "trig.level":
                var elm = _e("trig.level");
                elm.value = valueY;
                elm.dispatchEvent(new Event("change"));
                break;
            case "point-1":
                measure(0, valueX, valueY);
                break;
            case "point-2":
                measure(1, valueX, valueY);
                break;
        }
        drawControls();
    }

    function commonPicker(event) {
        var elm = event.target;

        var activated = elm.classList.contains("button-activated");
        var allActivated = document.getElementsByClassName("button-activated");
        for (var i = 0; i < allActivated.length; i++) {
            allActivated[i].classList.remove("button-activated");
        }
        if (activated) {
            disp.c.classList.remove("aiming");
            disp.c.removeEventListener("click", pickClick, true)
        } else {
            elm.classList.add("button-activated");
            disp.c.classList.add("aiming");
            disp.c.addEventListener("click", pickClick, true)
        }
    }


    function inputReset(event) {
        var elm = event.target;
        var valueElement = _e(elm.getAttribute("for"));
        if (valueElement !== null) {
            valueElement.value = elm.value;
            valueElement.dispatchEvent(new Event("change"))
        }
    }

    _addListener(".paramInput", "change", setParamFromInput);
    _addListener(".paramScreen", "change", setZoom);
    _addListener(".wheelSelect", "wheel", wheelSelect);
    _addListener(".vertical-picker", "click", commonPicker);
    _addListener(".measurement-picker", "click", commonPicker);
    _addListener(".inputReset", "click", inputReset);
    _addListener(".wheelChange", "wheel", wheelChange);

    disp.init();
    setZoom();
    initHW();
});

function updateGuiControl(name, value) {
    var elm = _e(name) || null;
    if (elm !== null && elm.value !== value) {
        elm.value = value;
        drawControls();
        updateExtVisuals(elm);
    }
}

var points = [null, null];
function measure(number, valueX, valueY) {
    points[number] = {x: valueX, y: valueY};
    updateOSD();
}
