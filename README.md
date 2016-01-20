##Open-Source Oscilloscope based on STM32F3-DISCOVERY board

Some ideas got from Tomasz Ostrowski's [Miniscope](http://tomeko.net/miniscope_v4/index.php?lang=en).
Tomasz has a bunch of ready-to-use-devices, and I have the only preliminary schematics and raw prototype.

The main idea is to build PC-oscilloscope. Hardware is ST Microelectronics development board
[STM32F3-DISCOVERY](http://www.st.com/web/catalog/tools/FM116/SC959/SS1532/PF254044) plus small additional board with simple protection circuits and basic voltage dividers.

###License:
[MIT](license.txt)

###Features:
* PC connectivity - USB
* Chrome App, platform independent
* Input voltage: 0..80V uni-polar
* Input impedance ~1MOhm
* Signal generator
* External/internal SYNC
* 12-bit sampling
* Channel GAIN up to x16
* Single channel mode:
 * One channel
 * Up to 3.5M samples/sec
* Multi-channel mode
 * Three channels
 * Up to 1.7M samples/sec
 
###Add-on board:
![Schematics](shematic_v1.png)
![Board](board_v1.png)
