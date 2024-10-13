#ifndef ASSEMBLER_ASSEMBLERMAPS_H
#define ASSEMBLER_ASSEMBLERMAPS_H

#include <unordered_map>
#include <string>

using namespace std;

class AssemblerMaps {
public:

    std::unordered_map<string, int> OPCODES;
    std::unordered_map<string, int> FUNC_CODES;
    std::unordered_map<string, int> REGISTERS;

    AssemblerMaps();
    int find(std::unordered_map<string, int> &map, std::__cxx11::basic_string<char> key);

private:
    void populateOpcodes();
    void populateFuncCodes();
    void populateRegisters();
};



#endif //ASSEMBLER_ASSEMBLERMAPS_H
