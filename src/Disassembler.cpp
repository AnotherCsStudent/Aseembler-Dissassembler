#include <iostream>
#include "Disassembler.h"
#include <vector>

Disassembler::Disassembler() = default;

string Disassembler::disassembleLine(int bin_line) {

}

void Disassembler::breakLine(int bin_line) {
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

    printf("Binary Instruction: ");
    for (int i = 0; i < 6; i++) {
        printf("%u ", instructions[i]);
    }

    return;
}
