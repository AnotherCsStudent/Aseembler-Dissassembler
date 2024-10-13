#include "AssemblerMaps.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

std::unordered_map<string, int> OPCODES = std::unordered_map<string, int>();
std::unordered_map<string, int> FUNC_CODES = std::unordered_map<string, int>();
std::unordered_map<string, int> REGISTERS = std::unordered_map<string, int>();

AssemblerMaps::AssemblerMaps() {
    populateOpcodes();
    populateFuncCodes();
    populateRegisters();
}

int AssemblerMaps::find(std::unordered_map<string, int>& map , string key) {
    auto it = map.find(key);

    if (it != map.end()) {
        return it->second;
    } else {
        std::cerr << "Warning: Token not found in HashMap";
        return 0b000000;
    }

}



void AssemblerMaps::populateOpcodes() {
    OPCODES.insert({"add", 0b000000});
    OPCODES.insert({"addi", 0b001000});
    OPCODES.insert({"sub", 0b000000});
    OPCODES.insert({"and", 0b000000});
    OPCODES.insert({"andi", 0b001100});
    OPCODES.insert({"or", 0b000000});
    OPCODES.insert({"ori", 0b001101});
    OPCODES.insert({"xor", 0b000000});
    OPCODES.insert({"xori", 0b001110});
    OPCODES.insert({"sll", 0b000000});
    OPCODES.insert({"srl", 0b000000});
    OPCODES.insert({"lw", 0b100011});
    OPCODES.insert({"sw", 0b101011});
    OPCODES.insert({"beq", 0b000100});
    OPCODES.insert({"bne", 0b000101});
    OPCODES.insert({"j", 0b000010});
    OPCODES.insert({"jal", 0b000011});
    OPCODES.insert({"jr", 0b000000});
    OPCODES.insert({"slt", 0b000000});
    OPCODES.insert({"slti", 0b001010});
}

void AssemblerMaps::populateFuncCodes() {
    FUNC_CODES.insert({"add", 0b100000});
    FUNC_CODES.insert({"sub", 0b100010});
    FUNC_CODES.insert({"and", 0b100100});
    FUNC_CODES.insert({"or", 0b100101});
    FUNC_CODES.insert({"xor", 0b100110});
    FUNC_CODES.insert({"sll", 0b000000});
    FUNC_CODES.insert({"srl", 0b000010});
    FUNC_CODES.insert({"jr", 0b001000});
    FUNC_CODES.insert({"slt", 0b101010});
}

void AssemblerMaps::populateRegisters() {
    REGISTERS.insert({"$zero", 0b00000});
    REGISTERS.insert({"$at", 0b00001});
    REGISTERS.insert({"$v0", 0b00010});
    REGISTERS.insert({"$v1", 0b00011});
    REGISTERS.insert({"$a0", 0b00100});
    REGISTERS.insert({"$a1", 0b00101});
    REGISTERS.insert({"$a2", 0b00110});
    REGISTERS.insert({"$a3", 0b00111});
    REGISTERS.insert({"$t0", 0b01000});
    REGISTERS.insert({"$t1", 0b01001});
    REGISTERS.insert({"$t2", 0b01010});
    REGISTERS.insert({"$t3", 0b01011});
    REGISTERS.insert({"$t4", 0b01100});
    REGISTERS.insert({"$t5", 0b01101});
    REGISTERS.insert({"$t6", 0b01110});
    REGISTERS.insert({"$t7", 0b01111});
    REGISTERS.insert({"$s0", 0b10000});
    REGISTERS.insert({"$s1", 0b10001});
    REGISTERS.insert({"$s2", 0b10010});
    REGISTERS.insert({"$s3", 0b10011});
    REGISTERS.insert({"$s4", 0b10100});
    REGISTERS.insert({"$s5", 0b10101});
    REGISTERS.insert({"$s6", 0b10110});
    REGISTERS.insert({"$s7", 0b10111});
    REGISTERS.insert({"$t8", 0b11000});
    REGISTERS.insert({"$t9", 0b11001});
    REGISTERS.insert({"$k0", 0b11010});
    REGISTERS.insert({"$k1", 0b11011});
    REGISTERS.insert({"$gp", 0b11100});
    REGISTERS.insert({"$sp", 0b11101});
    REGISTERS.insert({"$fp", 0b11110});
    REGISTERS.insert({"$ra", 0b11111});
}
