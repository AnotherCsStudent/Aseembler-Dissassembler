#include <iostream>
#include <vector>
#include <cstdint>
#include "Disassembler.h"


DisassemblerMaps map = DisassemblerMaps();

Disassembler::Disassembler() = default;

vector<int> Disassembler::breakChunk(int bin_line) {
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


string Disassembler::assembleLine(vector<int> chunkedLine) {

    string returnLine = "";

    // deal with r-type instructions
    if (chunkedLine[0] == 0) {

        returnLine += map.find(map.FUNC_CODES, chunkedLine[5]) + " ";
        returnLine += map.find(map.REGISTERS, chunkedLine[3]) + ", ";
        returnLine += map.find(map.REGISTERS, chunkedLine[1]) + ", ";
        returnLine += map.find(map.REGISTERS, chunkedLine[2]) + " ";
    // don't include jump-type instructions; so this is i-type instructions
    } else if (chunkedLine[0] != 0x02 && chunkedLine[0] != 0x03) {
        returnLine += map.find(map.OPCODES, chunkedLine[0]) + " ";
        returnLine += map.find(map.REGISTERS, chunkedLine[2]) + ", ";
        returnLine += map.find(map.REGISTERS, chunkedLine[1]) + ", ";

        short immediateValue = 0;
        immediateValue = immediateValue | chunkedLine[3];
        immediateValue = immediateValue << 5;
        immediateValue = immediateValue | chunkedLine[4];
        immediateValue = immediateValue << 6;
        immediateValue = immediateValue | chunkedLine[5];

        returnLine += to_string(immediateValue);

        // j-type value
    } else {
        returnLine += map.find(map.OPCODES, chunkedLine[0]) + " ";

        int jValue = 0;

        // merge
        jValue &= chunkedLine[1];
        jValue <<= 5;
        jValue &= chunkedLine[2];
        jValue <<= 5;
        jValue &= chunkedLine[3];
        jValue <<= 5;
        jValue &= chunkedLine[4];
        jValue <<= 6;
        jValue &= chunkedLine[5];

        returnLine += to_string(jValue);



    }

    return returnLine;
}
