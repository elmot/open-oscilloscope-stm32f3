cmake_minimum_required(VERSION 3.7)
project(f3_nucleo_oscilloscope C ASM)

set(CMAKE_CXX_STANDARD 11)

#add_definitions(-DSTM32L432xx -DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -DUNALIGNED_SUPPORT_DISABLE -DUSE_HAL -D__FPU_PRESENT=1 )
add_definitions(-D__weak=__attribute__\(\(weak\)\) -D__packed=__attribute__\(\(__packed__\)\) -DUSE_HAL_DRIVER -DSTM32F303xE )

file(GLOB_RECURSE SOURCES "startup/*.*" "Drivers/*.*" "Src/*.*" "Inc/*.*")

include_directories(Inc Drivers/STM32F3xx_HAL_Driver/Inc Drivers/STM32F3xx_HAL_Driver/Inc/Legacy Drivers/CMSIS/Device/ST/STM32F3xx/Include Drivers/CMSIS/Include)

add_executable(${PROJECT_NAME}.elf ${SOURCES} STM32F303RETx_FLASH.cmake ${LINKER_SCRIPT})

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map")

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE} 
Building ${BIN_FILE}")

add_custom_target(UPLOAD
        arm-none-eabi-gdb -iex "target remote tcp:127.0.0.1:3333"
        -iex "monitor program $<TARGET_FILE:${PROJECT_NAME}.elf>"
        -iex "monitor reset init"
        -iex "disconnect" -iex "quit")

