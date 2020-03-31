cmake_minimum_required(VERSION 3.13)

project(wolverine LANGUAGES C)
include(CTest)

set(TARGET false cache bool "Build for target")

if (${TARGET})

set(AVR_MCU "atmega328p")
add_definitions(-DF_CPU=16000000)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/avr-gcc.toolchain.cmake")

add_subdirectory(src)

endif()

if (NOT ${TARGET})
    add_subdirectory(unity)
    add_subdirectory(test)
endif()
