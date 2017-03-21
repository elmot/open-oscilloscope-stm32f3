#!/bin/bash
echo
echo START
echo
rm -r build
mkdir build
zip -r -9 build/release.zip USAGE.md DISCLAIMER.md win-drv license.txt
echo
echo
echo Build firmware
echo
echo
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=STM32F303xC.cmake ..
make dfu
zip -9 release.zip f3-oscill.hex f3-oscill.dfu
echo
echo
echo Build client
echo
echo
cd ../client
mvn clean install
cd target
zip -9 ../../build/release.zip osc-client.jar
cd ../..
