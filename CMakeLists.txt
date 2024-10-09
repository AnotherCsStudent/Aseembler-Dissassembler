cmake_minimum_required(VERSION 3.26)
project(Assembler)

set(CMAKE_CXX_STANDARD 23)

add_executable(Assembler src/main.cpp
        src/DisassemblerMaps.cpp
        src/DisassemblerMaps.h
        src/Disassembler.cpp
        src/Disassembler.h)
