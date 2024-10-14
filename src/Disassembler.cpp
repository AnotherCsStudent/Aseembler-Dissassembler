#include <iostream>
#include <vector>
#include <cstdint>
#include "Disassembler.h"


DisassemblerMaps map;

Disassembler::Disassembler() {
        map = DisassemblerMaps();
}


vector<int> Disassembler::chunkLine(int bin_line) {
    // this will be used to break the line down into each of its chunks
    vector<int> instructions;


    // get the right 6 bits
    // this insert is the equivalent of inserting at head
    instructions.insert(instructions.begin(), bin_line & 0b111111);
    // shift left 6 bits
    bin_line = bin_line >> 6;
    // capture the next 5 bit chunk
    instructions.insert(instructions.begin(), bin_line & 0b11111);
    // shift
    bin_line = bin_line >> 5;
    instructions.insert(instructions.begin(), bin_line & 0b11111);
    bin_line = bin_line >> 5;
    instructions.insert(instructions.begin(), bin_line & 0b11111);
    bin_line = bin_line >> 5;
    instructions.insert(instructions.begin(), bin_line & 0b11111);
    bin_line = bin_line >> 5;
    // the first chunk of bits is 6 bits wide
    instructions.insert(instructions.begin(), bin_line & 0b111111);

    // instructions are now broken down into {6, 5, 5, 5, 5, 6} bit chunks
    return instructions;
}

string Disassembler::disassembleLine(vector<int> chunkedLine) {

    string returnLine = "";

    // deal with r-type instructions
    if (chunkedLine[0] == 0) {

        returnLine += this->map.find(this->map.FUNC_CODES_A, chunkedLine[5]) + " ";
        returnLine += this->map.find(this->map.REGISTERS_A, chunkedLine[3]) + ", ";
        returnLine += this->map.find(this->map.REGISTERS_A, chunkedLine[1]) + ", ";
        returnLine += this->map.find(this->map.REGISTERS_A, chunkedLine[2]) + " ";
    // don't include jump-type instructions; so this is i-type instructions
    } else if (chunkedLine[0] != 0x02 && chunkedLine[0] != 0x03) {
        returnLine += this->map.find(this->map.OPCODES_A, chunkedLine[0]) + " ";
        returnLine += this->map.find(this->map.REGISTERS_A, chunkedLine[2]) + ", ";
        returnLine += this->map.find(this->map.REGISTERS_A, chunkedLine[1]) + ", ";

        // use a short here to C++ automatically deals with interpreting the 16-bit number
        short immediateValue = 0;
        immediateValue = immediateValue | chunkedLine[3];
        immediateValue = immediateValue << 5;
        immediateValue = immediateValue | chunkedLine[4];
        immediateValue = immediateValue << 6;
        immediateValue = immediateValue | chunkedLine[5];

        returnLine += to_string(immediateValue);

        // j-type value
    } else {
        returnLine += this->map.find(this->map.OPCODES_A, chunkedLine[0]) + " ";

        signed int jValue = 0;

        // figure out the sign bit
        jValue <<= 7;

        // merge
        // remove the sign bit
        jValue |= chunkedLine[1] & 0b11111;
        jValue <<= 5;
        jValue |= chunkedLine[2];
        jValue <<= 5;
        jValue |= chunkedLine[3];
        jValue <<= 5;
        jValue |= chunkedLine[4];
        jValue <<= 6;
        jValue |= chunkedLine[5];

        returnLine += to_string(jValue);
    }

    return returnLine;
}

std::string Disassembler::disassembleChunk(int chunk) {
    return disassembleLine(chunkLine(chunk));
}
