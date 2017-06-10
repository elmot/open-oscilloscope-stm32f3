from string import Template
import xml.etree.ElementTree
import logging
from functools import reduce

logging.basicConfig(level=logging.DEBUG)

logging.info('Reading eclipse project...')
project = xml.etree.ElementTree.parse('.project').getroot()
cproject = xml.etree.ElementTree.parse('.cproject').getroot()
cconfig = cproject.find("storageModule/cconfiguration[1]")

params = {}
params["projectName"] = project.find("name").text
params["linkerScript"] = cproject.find(".//*[@superClass='fr.ac6.managedbuild.tool.gnu.cross.c.linker.script']").get(
    "value").replace("../", "")
params["genericConfigName"] = params["linkerScript"].replace(".ld", "")
params["linkerFlags"] = cproject.find(".//*[@superClass='gnu.c.link.option.ldflags']").get("value")
cmakeFileName = Template("${genericConfigName}.cmake").substitute(params)
params["cmakeFileName"] = cmakeFileName

params["defines"] = reduce(lambda x, y: x + " " + y,
                           list(map(lambda x: "-D" + x.get("value").replace("(", "\\(").replace(")", "\\)").replace('"',
                                                                                                                    ''),
                                    cconfig.findall(
                                        ".//*[@superClass='gnu.c.compiler.option.preprocessor.def.symbols']/listOptionValue")
                                    )))
params["includes"] = reduce(lambda x, y: x + " " + y,
                            list(map(lambda x: x.get("value").replace("../", ""),
                                     cconfig.findall(
                                         ".//*[@superClass='gnu.c.compiler.option.include.paths']/listOptionValue")
                                     )))
params["sources"] = reduce(lambda x, y: x + " " + y,
                           list(map(lambda x: "\"" + x.get("name") + "/*.*\"",
                                    cconfig.findall(
                                        ".//sourceEntries/entry")
                                    )))

# todo compilerFlags
# todo source files

logging.info(params)

cmakeText = \
    Template(
        # @formatter:off
"""#
#-DCMAKE_TOOLCHAIN_FILE=${genericConfigName}.cmake
#
SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_VERSION 1)

# specify the cross compiler
SET(CMAKE_C_COMPILER_WORKS 1)
SET(CMAKE_C_COMPILER arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER arm-none-eabi-g++)

SET(LINKER_SCRIPT $${CMAKE_SOURCE_DIR}/${linkerScript})
#Uncomment for software floating point
#SET(COMMON_FLAGS "-mcpu=cortex-m4 -mthumb -mthumb-interwork -mfloat-abi=soft -ffunction-sections -fdata-sections -g -fno-common -fmessage-length=0 ${linkerFlags}")
SET(COMMON_FLAGS "-mcpu=cortex-m4 -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -ffunction-sections -fdata-sections -Og -g -fno-common -fmessage-length=0 ${linkerFlags}")
SET(CMAKE_CXX_FLAGS_INIT "$${COMMON_FLAGS} -std=c++11")
SET(CMAKE_C_FLAGS_INIT "$${COMMON_FLAGS} -std=gnu99")
SET(CMAKE_EXE_LINKER_FLAGS_INIT "-Wl,-gc-sections -T $${LINKER_SCRIPT}")
"""
        #@formatter:on
    ).substitute(params)

print(cmakeText, file=open(cmakeFileName, 'w'), flush=True)

cmakeListsText = \
    Template(
        # @formatter:off
"""cmake_minimum_required(VERSION 3.7)
project(${projectName} C ASM)

set(CMAKE_CXX_STANDARD 11)

#add_definitions(-DSTM32L432xx -DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -DUNALIGNED_SUPPORT_DISABLE -DUSE_HAL -D__FPU_PRESENT=1 )
add_definitions(${defines} )

file(GLOB_RECURSE SOURCES ${sources})

include_directories(${includes})

add_executable($${PROJECT_NAME}.elf $${SOURCES} ${cmakeFileName} $${LINKER_SCRIPT})

set(CMAKE_EXE_LINKER_FLAGS "$${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=$${PROJECT_BINARY_DIR}/$${PROJECT_NAME}.map")

set(HEX_FILE $${PROJECT_BINARY_DIR}/$${PROJECT_NAME}.hex)
set(BIN_FILE $${PROJECT_BINARY_DIR}/$${PROJECT_NAME}.bin)

add_custom_command(TARGET $${PROJECT_NAME}.elf POST_BUILD
        COMMAND $${CMAKE_OBJCOPY} -Oihex $$<TARGET_FILE:$${PROJECT_NAME}.elf> $${HEX_FILE}
        COMMAND $${CMAKE_OBJCOPY} -Obinary $$<TARGET_FILE:$${PROJECT_NAME}.elf> $${BIN_FILE}
        COMMENT "Building $${HEX_FILE} \nBuilding $${BIN_FILE}")

add_custom_target(UPLOAD
        arm-none-eabi-gdb -iex "target remote tcp:127.0.0.1:3333"
        -iex "monitor program $$<TARGET_FILE:$${PROJECT_NAME}.elf>"
        -iex "monitor reset init"
        -iex "disconnect" -iex "quit")
"""
        #@formatter:on
    ).substitute(params)

print(cmakeListsText, file=open("CMakeLists.txt", 'w'), flush=True)
