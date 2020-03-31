cmake_minimum_required(VERSION 3.13)

set(FINAL false CACHE BOOL "Build for target")

if (${FINAL})
    set(AVR_MCU "atmega328p")
    add_definitions(-DF_CPU=16000000)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/avr-gcc.toolchain.cmake")
endif()

project(wolverine LANGUAGES C)

if (${FINAL})
    add_subdirectory(src)
endif()

if (NOT ${FINAL})
    include(CTest)
    add_subdirectory(unity)
    add_subdirectory(test)
endif()
