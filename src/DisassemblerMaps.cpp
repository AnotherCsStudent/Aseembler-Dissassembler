#include "DisassemblerMaps.h"
#include <unordered_map>
#include <iostream>

// _A added to this because C++ is having a C++ moment
std::unordered_map<int, std::string> OPCODES_A = std::unordered_map<int, std::string>();
std::unordered_map<int, std::string> FUNC_CODES_A = std::unordered_map<int, std::string>();
std::unordered_map<int, std::string> REGISTERS_A = std::unordered_map<int, std::string>();

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
    OPCODES_A.insert({0x00, "SPECIAL"});  // R-type instructions
    OPCODES_A.insert({0x01, "BRANCH"});   // Branch instructions

    // Immediate type instructions
    OPCODES_A.insert({0x02, "J"});
    OPCODES_A.insert({0x03, "JAL"});
    OPCODES_A.insert({0x04, "BEQ"});
    OPCODES_A.insert({0x05, "BNE"});
    OPCODES_A.insert({0x06, "BLEZ"});
    OPCODES_A.insert({0x07, "BGTZ"});
    OPCODES_A.insert({0x08, "ADDI"});
    OPCODES_A.insert({0x09, "ADDIU"});
    OPCODES_A.insert({0x0A, "SLTI"});
    OPCODES_A.insert({0x0B, "SLTIU"});
    OPCODES_A.insert({0x0C, "ANDI"});
    OPCODES_A.insert({0x0D, "ORI"});
    OPCODES_A.insert({0x0E, "XORI"});
    OPCODES_A.insert({0x0F, "LUI"});

    // Load and store instructions
    OPCODES_A.insert({0x20, "LB"});
    OPCODES_A.insert({0x21, "LH"});
    OPCODES_A.insert({0x22, "LWL"});
    OPCODES_A.insert({0x23, "LW"});
    OPCODES_A.insert({0x24, "LBU"});
    OPCODES_A.insert({0x25, "LHU"});
    OPCODES_A.insert({0x26, "LWR"});
    OPCODES_A.insert({0x28, "SB"});
    OPCODES_A.insert({0x29, "SH"});
    OPCODES_A.insert({0x2A, "SWL"});
    OPCODES_A.insert({0x2B, "SW"});
    OPCODES_A.insert({0x2E, "SWR"});
}

void DisassemblerMaps::populateFuncCodes() {
    FUNC_CODES_A.insert({0x20, "ADD"});
    FUNC_CODES_A.insert({0x21, "ADDU"});
    FUNC_CODES_A.insert({0x22, "SUB"});
    FUNC_CODES_A.insert({0x23, "SUBU"});
    FUNC_CODES_A.insert({0x24, "AND"});
    FUNC_CODES_A.insert({0x25, "OR"});
    FUNC_CODES_A.insert({0x26, "XOR"});
    FUNC_CODES_A.insert({0x27, "NOR"});
    FUNC_CODES_A.insert({0x2A, "SLT"});
    FUNC_CODES_A.insert({0x2B, "SLTU"});

    // Shift instructions
    FUNC_CODES_A.insert({0x00, "SLL"});
    FUNC_CODES_A.insert({0x02, "SRL"});
    FUNC_CODES_A.insert({0x03, "SRA"});
    FUNC_CODES_A.insert({0x04, "SLLV"});
    FUNC_CODES_A.insert({0x06, "SRLV"});
    FUNC_CODES_A.insert({0x07, "SRAV"});

    // Jump and move instructions
    FUNC_CODES_A.insert({0x08, "JR"});
    FUNC_CODES_A.insert({0x09, "JALR"});
    FUNC_CODES_A.insert({0x0C, "SYSCALL"});
    FUNC_CODES_A.insert({0x0D, "BREAK"});

// Multiplication and division instructions
    FUNC_CODES_A.insert({0x18, "MULT"});
    FUNC_CODES_A.insert({0x19, "MULTU"});
    FUNC_CODES_A.insert({0x1A, "DIV"});
    FUNC_CODES_A.insert({0x1B, "DIVU"});

    // Load/Store from HI/LO registers
    FUNC_CODES_A.insert({0x10, "MFHI"});
    FUNC_CODES_A.insert({0x11, "MTHI"});
    FUNC_CODES_A.insert({0x12, "MFLO"});
    FUNC_CODES_A.insert({0x13, "MTLO"});
}

void DisassemblerMaps::populateRegisters() {
    REGISTERS_A.insert({0x00, "$zero"});
    REGISTERS_A.insert({0x01, "$at"});
    REGISTERS_A.insert({0x02, "$v0"});
    REGISTERS_A.insert({0x03, "$v1"});
    REGISTERS_A.insert({0x04, "$a0"});
    REGISTERS_A.insert({0x05, "$a1"});
    REGISTERS_A.insert({0x06, "$a2"});
    REGISTERS_A.insert({0x07, "$a3"});
    REGISTERS_A.insert({0x08, "$t0"});
    REGISTERS_A.insert({0x09, "$t1"});
    REGISTERS_A.insert({0x0A, "$t2"});
    REGISTERS_A.insert({0x0B, "$t3"});
    REGISTERS_A.insert({0x0C, "$t4"});
    REGISTERS_A.insert({0x0D, "$t5"});
    REGISTERS_A.insert({0x0E, "$t6"});
    REGISTERS_A.insert({0x0F, "$t7"});
    REGISTERS_A.insert({0x10, "$s0"});
    REGISTERS_A.insert({0x11, "$s1"});
    REGISTERS_A.insert({0x12, "$s2"});
    REGISTERS_A.insert({0x13, "$s3"});
    REGISTERS_A.insert({0x14, "$s4"});
    REGISTERS_A.insert({0x15, "$s5"});
    REGISTERS_A.insert({0x16, "$s6"});
    REGISTERS_A.insert({0x17, "$s7"});
    REGISTERS_A.insert({0x18, "$t8"});
    REGISTERS_A.insert({0x19, "$t9"});
    REGISTERS_A.insert({0x1A, "$k0"});
    REGISTERS_A.insert({0x1B, "$k1"});
    REGISTERS_A.insert({0x1C, "$gp"});
    REGISTERS_A.insert({0x1D, "$sp"});
    REGISTERS_A.insert({0x1E, "$fp"});
    REGISTERS_A.insert({0x1F, "$ra"});
}




