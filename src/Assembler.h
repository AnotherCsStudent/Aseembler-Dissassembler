#ifndef ASSEMBLER_ASSEMBLER_H
#define ASSEMBLER_ASSEMBLER_H


#include <vector>
#include <string>

class Assembler {
public:
    std::vector<std::string> split(std::string inputString, char delimiter);

    std::string strip(std::string inputString, char deleteChar);

    int parseLine(std::string inputString);
};


#endif //ASSEMBLER_ASSEMBLER_H
