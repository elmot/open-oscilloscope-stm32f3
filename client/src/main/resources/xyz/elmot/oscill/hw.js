var usbConnection = null;
var openDevice = null;
//var cmdQueue = [];
var frameParam = {w: 2047, h: 4096};

/**
 @type {CanvasRenderingContext2D}
 */


var data = [null, null, null, null, null, null];


function setParam(name, value) {
//    cmdQueue.push(name + "=" + value)
    console.log(oscilloscope)
   window.oscilloscope.test();
    oscilloscope.sendCommand(name,value);
}






