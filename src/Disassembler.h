#include <string>
#include <vector>
#include "DisassemblerMaps.h"

using namespace std;

#ifndef ASSEMBLER_DISASSEMBLER_H
#define ASSEMBLER_DISASSEMBLER_H

class Disassembler {
public:
    Disassembler();
    std::vector<int> chunkLine(int bin_line);
    std::string disassembleLine(vector<int> chunkedLine);
    string disassembleChunk(int chunk);
private:
    DisassemblerMaps map;

};

#endif //ASSEMBLER_DISASSEMBLER_H
