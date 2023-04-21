cmake_minimum_required(VERSION 3.16)

set(VERSION 1.0)

set(RISCV_TOOLCHAIN_PATH "/opt/riscv/bin")
set(RISCV_TOOLCHAIN_PREFIX "riscv64-unknown-elf")
set(RISCV_ARCH "rv32im")
set(RISCV_ABI "ilp32")

#set(CMAKE_SYSTEM_NAME               CDAC Vega)
set(CMAKE_SYSTEM_PROCESSOR          riscv)

set(CMAKE_TRY_COMPILE_TARGET_TYPE   STATIC_LIBRARY)

set(CMAKE_AR                        ${RISCV_TOOLCHAIN_PATH}//${RISCV_TOOLCHAIN_PREFIX}-ar${CMAKE_EXECUTABLE_SUFFIX})
set(CMAKE_ASM_COMPILER              ${RISCV_TOOLCHAIN_PATH}/${RISCV_TOOLCHAIN_PREFIX}-gcc${CMAKE_EXECUTABLE_SUFFIX})
set(CMAKE_C_COMPILER                ${RISCV_TOOLCHAIN_PATH}/${RISCV_TOOLCHAIN_PREFIX}-gcc${CMAKE_EXECUTABLE_SUFFIX})
set(CMAKE_CXX_COMPILER              ${RISCV_TOOLCHAIN_PATH}/${RISCV_TOOLCHAIN_PREFIX}-g++${CMAKE_EXECUTABLE_SUFFIX})
set(CMAKE_LINKER                    ${RISCV_TOOLCHAIN_PATH}/${RISCV_TOOLCHAIN_PREFIX}-ld${CMAKE_EXECUTABLE_SUFFIX})
set(CMAKE_OBJCOPY                   ${RISCV_TOOLCHAIN_PATH}/${RISCV_TOOLCHAIN_PREFIX}-objcopy${CMAKE_EXECUTABLE_SUFFIX} CACHE INTERNAL "")
set(CMAKE_RANLIB                    ${RISCV_TOOLCHAIN_PATH}/${RISCV_TOOLCHAIN_PREFIX}-ranlib${CMAKE_EXECUTABLE_SUFFIX} CACHE INTERNAL "")
set(CMAKE_SIZE                      ${RISCV_TOOLCHAIN_PATH}/${RISCV_TOOLCHAIN_PREFIX}-size${CMAKE_EXECUTABLE_SUFFIX} CACHE INTERNAL "")
set(CMAKE_STRIP                     ${RISCV_TOOLCHAIN_PATH}/${RISCV_TOOLCHAIN_PREFIX}-strip${CMAKE_EXECUTABLE_SUFFIX} CACHE INTERNAL "")
#-march=rv32im -mabi=ilp32
#set(CMAKE_C_FLAGS                   "-march=rv32im -mabi=ilp32 -mcmodel=medany -Wl,--gc-sections -Wl,-Map=${OUTPUT_NAME}.map -nostartfiles -fno-builtin-printf -fno-builtin-puts -fdata-sections -ffunction-sections -fno-builtin-memcmp" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS                 "${CMAKE_C_FLAGS}" CACHE INTERNAL "")

#set(CMAKE_C_FLAGS_DEBUG             "-Og -g" CACHE INTERNAL "")
#set(CMAKE_C_FLAGS_RELEASE           "-O3 -DNDEBUG" CACHE INTERNAL "")
#set(CMAKE_CXX_FLAGS_DEBUG           "${CMAKE_C_FLAGS_DEBUG}" CACHE INTERNAL "")
#set(CMAKE_CXX_FLAGS_RELEASE         "${CMAKE_C_FLAGS_RELEASE}" CACHE INTERNAL "")

#set(CMAKE_STATIC_LINKER_FLAGS       "-march=rv32im -mabi=ilp32 -Wl,--gc-sections -Wl,-Map,${OUTPUT_NAME}.map -nostartfiles -nostdlib -mcmodel=medany -fno-builtin-printf -fno-builtin-puts -fdata-sections -ffunction-sections -fno-builtin-memcmp --specs=nano.specs -specs=nosys.specs")
set(CMAKE_EXE_LINKER_FLAGS                   "--specs=nano.specs  -march=rv32im -mabi=ilp32 -mcmodel=medany -T/home/rnayabed/code/rnayabed/taurus/common/mbl.lds -Wl,--gc-sections -Wl,-Map=${OUTPUT_NAME}.map -nostartfiles -fno-builtin-printf -fno-builtin-puts -fdata-sections -ffunction-sections -fno-builtin-memcmp" CACHE INTERNAL "")


set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)



list(APPEND CMAKE_PREFIX_PATH "/home/rnayabed/code/rnayabed/gg/tt")

find_package(taurus 1.0 REQUIRED)
set(CMAKE_VERBOSE_MAKEFILE ON)
project(led_toggle 
    VERSION ${VERSION}
    LANGUAGES C
    DESCRIPTION "LED Toggle")



add_executable(led_toggle
    led_toggle.c
)

#target_compile_options(led_toggle
#    PUBLIC
#    -T/home/rnayabed/code/rnayabed/taurus/common/mbl.lds -lc -lgcc -lm -march=rv32im -mabi=ilp32 -mcmodel=medany -Wl,--gc-sections -Wl,-Map=${OUTPUT_NAME}.map -nostartfiles -fno-builtin-printf -fno-builtin-puts -fdata-sections -ffunction-sections -fno-builtin-memcmp
#)

target_link_libraries(led_toggle 
PRIVATE taurus::taurus)
