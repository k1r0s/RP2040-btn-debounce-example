cmake_minimum_required(VERSION 3.16)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
pico_sdk_init()

project(main)

add_executable(main main.c)

target_link_libraries(main pico_stdlib hardware_i2c hardware_irq)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

pico_add_extra_outputs(main)
