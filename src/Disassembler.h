#include <string>
#include <vector>
#include "DisassemblerMaps.h"

using namespace std;

#ifndef ASSEMBLER_DISASSEMBLER_H
#define ASSEMBLER_DISASSEMBLER_H

class Disassembler {
public:
    Disassembler();
    std::vector<int> breakChunk(int bin_line);
    std::string assembleLine(std::vector<int> chunkedLine);
private:
    DisassemblerMaps maps;
};

#endif //ASSEMBLER_DISASSEMBLER_H
