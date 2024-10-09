#ifndef ASSEMBLER_DISASSEMBLERMAPS_H
#define ASSEMBLER_DISASSEMBLERMAPS_H

#include <unordered_map>
#include <string>

class DisassemblerMaps {
public:
    DisassemblerMaps();
    std::unordered_map<int, std::string> OPCODES;
    std::unordered_map<int, std::string> FUNC_CODES;
    std::unordered_map<int, std::string> REGISTERS;

    std::string find(std::unordered_map<int, std::string> &map, int key);

private:
    void populateOpcodes();
    void populateFuncCodes();
    void populateRegisters();


};


#endif //ASSEMBLER_DISASSEMBLERMAPS_H
