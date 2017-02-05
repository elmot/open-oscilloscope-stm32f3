project(f3-oscill C ASM)
cmake_minimum_required(VERSION 3.5.0)

add_definitions(-DSTM32F303xC)

file(GLOB_RECURSE USER_SOURCES "Src/*.c" "Inc/*.h")
file(GLOB_RECURSE HAL_SOURCES "Drivers/STM32F3xx_HAL_Driver/Inc/*.h" "Drivers/STM32F3xx_HAL_Driver/Src/*.c")
file(GLOB_RECURSE USB_SOURCES "Middlewares/ST/STM32_USB_Device_Library/Core/Inc/*.h"
        "Middlewares/ST/STM32_USB_Device_Library/Core/Src/*.c"
        "Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc/*.h"
        "Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/*.c")

add_library(CMSIS startup/startup_stm32f303xc.s)

include_directories(Inc)
include_directories(Drivers/STM32F3xx_HAL_Driver/Inc)
include_directories(Drivers/CMSIS/Include)
include_directories(Drivers/CMSIS/Device/ST/STM32F3xx/Include)

include_directories(Middlewares/ST/STM32_USB_Device_Library/Core/Inc)
include_directories(Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc)


add_executable(${PROJECT_NAME}.elf ${USER_SOURCES} ${HAL_SOURCES} ${USB_SOURCES} ${LINKER_SCRIPT})

target_link_libraries(${PROJECT_NAME}.elf CMSIS )

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=${PROJECT_SOURCE_DIR}/${PROJECT_NAME}.map")
set(HEX_FILE ${PROJECT_SOURCE_DIR}/build/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_SOURCE_DIR}/build/${PROJECT_NAME}.bin)
#[[
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE} \nBuilding ${BIN_FILE}")
]]
