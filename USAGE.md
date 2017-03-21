### Equipment
The project utilizes STM32F3-Discovery board and special protection shield.

 
### Shield board
Using of shield board is highly recommended, since it protects MCU input pins from overvoltage, 
and, thus, from equipment damage. Without that board you can measure voltages only positive 
within 0..3V range. After soldering and attaching the board ensure that all the 
electrical connections and soldering point are made properly and are reliable enough. 

### Flashing firmware
The oscilloscope firmware is shipped in two formats - "Intel hex" and "STM DFU". You can use any of these.

#### Windows
##### HEX
To flash shipped .hex file:
* connect *central* USB connector to your computer
* use [STM32 ST-LINK utility](http://www.st.com/en/embedded-software/stsw-link004.html) to download the *f3-oscill.hex* into the MCU

##### DFU
To flash shipped *.dfu* file:
* before powering on the board, connect *boot0* and *VDD* pins with a jumper. 
* connect *right-side* USB connector to your computer
* use [DfuSE utility](http://www.st.com/content/st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-programmers/stsw-stm32080.html)
 to download the *f3-oscill.dfu* into the MCU
* Disconnect usb, remove jumper
#### Linux/Mac
##### HEX
To flash shipped .hex file:
* connect *central* USB connector to your computer
* use [OPenOCD](http://openocd.org/) to download the *f3-oscill.hex* into the MCU

##### DFU
To flash shipped *.dfu* file:
* before powering on the board, connect *boot0* and *VDD* pins with a jumper. 
* connect *right-side* USB connector to your computer
* use *dfu-tool*
 to download the *f3-oscill.dfu* into the MCU (`dfu-tool write f3-oscill.dfu`)
* Disconnect usb, remove jumper

### Client Software
To run the client software:
* __Windows only__. Please install shipped *STM32 Virtual Com Port driver* from *win-drv* folder. 
* Install JRE (Java Runtime Environment) or JDK (Java Development Kit) version 8
* connect *right-side* USB connector to your computer
* run the command:
`java -jar osc-client.jar [-options] [COM port name]`

Supported options:
  
* *-web* - run webserver + native browser instead of java application.
* *-opengl* - run the application in OpenGL mode. *Note!* It causes serious memory leaks on some platforms
* *-help* - print usage information
* *portname* - optional virtual COM port name

  
