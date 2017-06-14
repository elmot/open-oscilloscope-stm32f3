var frameParam = {w: 1400, h: 4096, vertGridN: 14, horGridN: 10};

/**
 @type {CanvasRenderingContext2D}
 */


//var data = [null, null, null, null, null, null];


function setParam(name, value) {
    osc.sendCommand(name + "=" +  value);
}

function initHW() {
    let frame = [];
    const shell = require('child_process');
    shell.exec("stty -F /dev/ttyACM0 1152000")

    const readline = require('readline');
    const fs = require('fs');
    const rl = readline.createInterface({
        input: fs.createReadStream('/dev/ttyACM0')
    });

    rl.on('line', function (line) {
        if (line === "FRAME") {
            frame = [];
        } else if (line === "END") {
            drawData([frame])
        } else
        {
            frame.push(parseInt(line, 16))
        }
    });
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

