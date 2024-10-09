#include "DisassemblerMaps.h"
#include <unordered_map>
#include <iostream>

std::unordered_map<int, std::string> OPCODES = std::unordered_map<int, std::string>();
std::unordered_map<int, std::string> FUNC_CODES = std::unordered_map<int, std::string>();
std::unordered_map<int, std::string> REGISTERS = std::unordered_map<int, std::string>();

DisassemblerMaps::DisassemblerMaps() {
    populateOpcodes();
    populateFuncCodes();
    populateRegisters();
}

std::string DisassemblerMaps::find(std::unordered_map<int, std::string>& map , int key) {
    auto it = map.find(key);

    if (it != map.end()) {
        return it->second;
    } else {
        std::cerr << "Warning: Token not found in HashMap";
        return "-------------------";
    }

}

void DisassemblerMaps::populateOpcodes() {
    OPCODES.insert({0x00, "SPECIAL"});  // R-type instructions
    OPCODES.insert({0x01, "BRANCH"});   // Branch instructions

    // Immediate type instructions
    OPCODES.insert({0x02, "J"});
    OPCODES.insert({0x03, "JAL"});
    OPCODES.insert({0x04, "BEQ"});
    OPCODES.insert({0x05, "BNE"});
    OPCODES.insert({0x06, "BLEZ"});
    OPCODES.insert({0x07, "BGTZ"});
    OPCODES.insert({0x08, "ADDI"});
    OPCODES.insert({0x09, "ADDIU"});
    OPCODES.insert({0x0A, "SLTI"});
    OPCODES.insert({0x0B, "SLTIU"});
    OPCODES.insert({0x0C, "ANDI"});
    OPCODES.insert({0x0D, "ORI"});
    OPCODES.insert({0x0E, "XORI"});
    OPCODES.insert({0x0F, "LUI"});

    // Load and store instructions
    OPCODES.insert({0x20, "LB"});
    OPCODES.insert({0x21, "LH"});
    OPCODES.insert({0x22, "LWL"});
    OPCODES.insert({0x23, "LW"});
    OPCODES.insert({0x24, "LBU"});
    OPCODES.insert({0x25, "LHU"});
    OPCODES.insert({0x26, "LWR"});
    OPCODES.insert({0x28, "SB"});
    OPCODES.insert({0x29, "SH"});
    OPCODES.insert({0x2A, "SWL"});
    OPCODES.insert({0x2B, "SW"});
    OPCODES.insert({0x2E, "SWR"});
}

void DisassemblerMaps::populateFuncCodes() {
    FUNC_CODES.insert({0x20, "ADD"});
    FUNC_CODES.insert({0x21, "ADDU"});
    FUNC_CODES.insert({0x22, "SUB"});
    FUNC_CODES.insert({0x23, "SUBU"});
    FUNC_CODES.insert({0x24, "AND"});
    FUNC_CODES.insert({0x25, "OR"});
    FUNC_CODES.insert({0x26, "XOR"});
    FUNC_CODES.insert({0x27, "NOR"});
    FUNC_CODES.insert({0x2A, "SLT"});
    FUNC_CODES.insert({0x2B, "SLTU"});

    // Shift instructions
    FUNC_CODES.insert({0x00, "SLL"});
    FUNC_CODES.insert({0x02, "SRL"});
    FUNC_CODES.insert({0x03, "SRA"});
    FUNC_CODES.insert({0x04, "SLLV"});
    FUNC_CODES.insert({0x06, "SRLV"});
    FUNC_CODES.insert({0x07, "SRAV"});

    // Jump and move instructions
    FUNC_CODES.insert({0x08, "JR"});
    FUNC_CODES.insert({0x09, "JALR"});
    FUNC_CODES.insert({0x0C, "SYSCALL"});
    FUNC_CODES.insert({0x0D, "BREAK"});

// Multiplication and division instructions
    FUNC_CODES.insert({0x18, "MULT"});
    FUNC_CODES.insert({0x19, "MULTU"});
    FUNC_CODES.insert({0x1A, "DIV"});
    FUNC_CODES.insert({0x1B, "DIVU"});

    // Load/Store from HI/LO registers
    FUNC_CODES.insert({0x10, "MFHI"});
    FUNC_CODES.insert({0x11, "MTHI"});
    FUNC_CODES.insert({0x12, "MFLO"});
    FUNC_CODES.insert({0x13, "MTLO"});
}

void DisassemblerMaps::populateRegisters() {
    REGISTERS.insert({0x00, "$zero"});
    REGISTERS.insert({0x01, "$at"});
    REGISTERS.insert({0x02, "$v0"});
    REGISTERS.insert({0x03, "$v1"});
    REGISTERS.insert({0x04, "$a0"});
    REGISTERS.insert({0x05, "$a1"});
    REGISTERS.insert({0x06, "$a2"});
    REGISTERS.insert({0x07, "$a3"});
    REGISTERS.insert({0x08, "$t0"});
    REGISTERS.insert({0x09, "$t1"});
    REGISTERS.insert({0x0A, "$t2"});
    REGISTERS.insert({0x0B, "$t3"});
    REGISTERS.insert({0x0C, "$t4"});
    REGISTERS.insert({0x0D, "$t5"});
    REGISTERS.insert({0x0E, "$t6"});
    REGISTERS.insert({0x0F, "$t7"});
    REGISTERS.insert({0x10, "$s0"});
    REGISTERS.insert({0x11, "$s1"});
    REGISTERS.insert({0x12, "$s2"});
    REGISTERS.insert({0x13, "$s3"});
    REGISTERS.insert({0x14, "$s4"});
    REGISTERS.insert({0x15, "$s5"});
    REGISTERS.insert({0x16, "$s6"});
    REGISTERS.insert({0x17, "$s7"});
    REGISTERS.insert({0x18, "$t8"});
    REGISTERS.insert({0x19, "$t9"});
    REGISTERS.insert({0x1A, "$k0"});
    REGISTERS.insert({0x1B, "$k1"});
    REGISTERS.insert({0x1C, "$gp"});
    REGISTERS.insert({0x1D, "$sp"});
    REGISTERS.insert({0x1E, "$fp"});
    REGISTERS.insert({0x1F, "$ra"});
}




