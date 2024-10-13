#ifndef ASSEMBLER_DISASSEMBLERMAPS_H
#define ASSEMBLER_DISASSEMBLERMAPS_H

#include <unordered_map>
#include <string>

class DisassemblerMaps {
public:
    DisassemblerMaps();
    std::unordered_map<int, std::string> OPCODES_A;
    std::unordered_map<int, std::string> FUNC_CODES_A;
    std::unordered_map<int, std::string> REGISTERS_A;

    std::string find(std::unordered_map<int, std::string> &map, int key);

private:
    void populateOpcodes();
    void populateFuncCodes();
    void populateRegisters();


};


#endif //ASSEMBLER_DISASSEMBLERMAPS_H
