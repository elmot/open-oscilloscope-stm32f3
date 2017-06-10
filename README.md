<img align="right" width="200" src="client/icon.png">

## Open-Source Oscilloscope based on NUCLEO-F303RE

Some ideas got from Tomasz Ostrowski's [Miniscope](http://tomeko.net/miniscope_v4/index.php?lang=en).
Tomasz has a bunch of ready-to-use-devices, and I have the only preliminary schematics and raw prototype.

The main idea is to build PC-oscilloscope. Hardware is ST Microelectronics development board
[NUCLEO-F303RE](http://www.st.com/en/evaluation-tools/nucleo-f303re.html) plus small additional board with simple protection circuits and basic voltage dividers.

A special Java application or web browser is supposed to be a PC part of the system.

## DISCLAIMER

**! WARNING !**

Read [SAFETY DISCLAIMER](DISCLAIMER.md) before using any of materials listed here.  

### License:
[MIT](license.txt)

### Hardware variants
* Naked Nucleo
  * _No overvoltage protection_
  * Input voltage: 0..3V uni-polar
* Shield board + Nucleo
  * Overvoltage protection
  * Input voltage: 0..30V uni-polar
  * Max. input impedance ~200kOhm

### Usage HOWTO
TBD

### Build HOWTO

#### Required tools
* cmake 3.9.x
* arm-none-eabi-gcc 5.4 + binutils

#### Build firmware
* `mkdir target`
* `cd target`
* `cmake -DCMAKE_TOOLCHAIN_FILE=STM32F303RETx_FLASH.cmake ..`
* `make`

#### Flash firmware
* Connect NUCLEO board
* Copy generated file (_cmake-build-debug/f3_nucleo_oscilloscope.bin_) to NUCLEO virtual drive
* Unmount NUCLEO virtual drive
 
### Roadmap
See [ROADMAP.md](ROADMAP.md)

