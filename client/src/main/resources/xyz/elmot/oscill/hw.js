var frameParam = {w: 1400, h: 4096, vertGridN: 14, horGridN: 10};

/**
 @type {CanvasRenderingContext2D}
 */


//var data = [null, null, null, null, null, null];


function setParam(name, value) {
    osc.sendCommand(name + "=" +  value);
}

function initHW() {
}

function d() {
    document.getElementById("trig.level").value = 200
    var d = [[], []];
    var dx = Math.random();
    for (var i = 0; i < 1400; i++) {
        d[1][i] = 4000 * Math.sin(dx / 20 + i / 200);
        d[0][i] = 4000 * Math.sin(dx + i / 250);
    }
    drawData(d);
}

