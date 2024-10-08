#include <string>

using namespace std;

#ifndef ASSEMBLER_DISASSEMBLER_H
#define ASSEMBLER_DISASSEMBLER_H

class Disassembler {
public:
    Disassembler();
    string disassembleLine(int bin_line);
    void breakLine(int bin_line);
};

#endif //ASSEMBLER_DISASSEMBLER_H
