# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Tarefa-8-SD C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Tarefa-8-SD Tarefa-8-SD.c 
scr/botao.c
scr/init.c
scr/display.c
inc/ssd1306.c
)

pico_set_program_name(Tarefa-8-SD "Tarefa-8-SD")
pico_set_program_version(Tarefa-8-SD "0.1")

# Generate PIO header
pico_generate_pio_header(Tarefa-8-SD ${CMAKE_CURRENT_LIST_DIR}/blink.pio)

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Tarefa-8-SD 0)
pico_enable_stdio_usb(Tarefa-8-SD 1)

# Add the standard library to the build
target_link_libraries(Tarefa-8-SD
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(Tarefa-8-SD PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(Tarefa-8-SD 
        hardware_i2c
        hardware_pio
        hardware_adc
        hardware_clocks
        hardware_gpio
        )

pico_add_extra_outputs(Tarefa-8-SD)

