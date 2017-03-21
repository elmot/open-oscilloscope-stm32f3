#-DCMAKE_TOOLCHAIN_FILE=STM32F303xC.cmake
SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_VERSION 1)
# specify the cross compiler
SET(CMAKE_C_COMPILER_WORKS 1)
SET(CMAKE_C_COMPILER arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER arm-none-eabi-g++)

SET(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F303VCTx_FLASH.ld)

SET(COMMON_FLAGS "-g -mlittle-endian -mthumb -mcpu=cortex-m4 -march=armv7e-m -mfpu=fpv4-sp-d16 -mfloat-abi=hard -ffreestanding --specs=nano.specs  --specs=nosys.specs --specs=rdimon.specs")
#SET(COMMON_FLAGS "-mcpu=cortex-m0 -mthumb -mfloat-abi=soft -ffunction-sections -fdata-sections -g -fno-common -fmessage-length=0 --specs=nano.specs  --specs=nosys.specs ")
SET(CMAKE_CXX_FLAGS_INIT "${COMMON_FLAGS} -std=c++11")
SET(CMAKE_C_FLAGS_INIT "${COMMON_FLAGS} -std=gnu99")
SET(CMAKE_EXE_LINKER_FLAGS_INIT "-Wl,-gc-sections,-M=binary.map -T ${LINKER_SCRIPT}")
