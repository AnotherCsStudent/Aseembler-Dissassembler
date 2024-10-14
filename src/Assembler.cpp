#include "Assembler.h"
#include <iostream>
#include <vector>
#include "AssemblerMaps.h"
#include <cmath>
#include <bitset>
#include <cstdint>

using namespace std;

template <typename T> void printVector(vector<T> vec) {
    int i = 0;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << "{" << i << ", " << *it << "}, ";
        i++;
    }
    cout << endl;
}


vector<string> Assembler::split(string inputString, char delimiter) {
    vector<string> tokens = vector<string>();

    int initialIndex = 0;
    int endIndex = 0;
    for (string::iterator it = inputString.begin(); it != inputString.end(); it++) {
        if (*it == delimiter) {
            tokens.push_back(inputString.substr(initialIndex, endIndex - initialIndex));
            initialIndex = endIndex + 1;
        }
        endIndex++;
    }

    // flush the rest of the string into the tokens list
    tokens.push_back(inputString.substr(initialIndex, endIndex));

    return tokens;
}

string Assembler::strip(string inputString, char deleteChar) {
    string returnString = "";

    for (int i = 0; i < inputString.length(); i++) {
        if (inputString[i] != deleteChar) {
            returnString += inputString[i];
        }
    }

    return returnString;

}

int Assembler::parseLine(string inputString) {
    vector<string> returnTokens = split(inputString, ' ');
    vector<string> cleanedTokens = vector<string>();
    AssemblerMaps map = AssemblerMaps();

    // clean the commas out of the tokens
    for (int i = 0; i < returnTokens.size(); i++) {
        cleanedTokens.push_back(strip(returnTokens[i], ','));
    }

    vector<int> machineCode = vector<int>();
    int initialToken = map.find(map.OPCODES, cleanedTokens[0]);

    int machineCodeBits = 0;

    // r-type instructions
    if (initialToken == 0b000000) {
        machineCode.push_back(initialToken);
        int i = 0;
        for (i = 1; i < cleanedTokens.size(); i++) {
            machineCode.push_back(map.find(map.REGISTERS, cleanedTokens[i]));
        }
        // there are 4 register slots, and unfilled ones need to be filled with blank registers
        for (int j = 0; i <= 4; i++) {
            machineCode.push_back(0b00000);
        }
        machineCode.push_back(map.find(map.FUNC_CODES, cleanedTokens[0]));

        // machine code should have 6 segments (6-5-5-5-5-6), now combine them
        machineCodeBits |= machineCode[0];
        machineCodeBits <<= 6;
        // 2-1-3 because mips moment
        machineCodeBits |= machineCode[2];
        machineCodeBits <<= 5;
        machineCodeBits |= machineCode[3];
        machineCodeBits <<= 5;
        machineCodeBits |= machineCode[1];
        machineCodeBits <<= 5;
        machineCodeBits |= machineCode[4];
        machineCodeBits <<= 6;
        machineCodeBits |= machineCode[5];

    // j type instructions
    } else if (initialToken == 0b000010 || initialToken == 0b000011) {
        machineCode.push_back(map.find(map.OPCODES, cleanedTokens[0]));
        int literalValue = stoi(cleanedTokens[1]);
        machineCode.push_back(literalValue);

        machineCodeBits |= machineCode[0];
        machineCodeBits <<= 26;
        machineCodeBits |= machineCode[1];

    // i-type instructions
    } else {
        machineCode.push_back(map.find(map.OPCODES, cleanedTokens[0]));

        // only 1 register
        if (cleanedTokens.size() == 2) {
            machineCode.push_back(map.find(map.REGISTERS, cleanedTokens[1]));
            machineCode.push_back(0b00000);
            machineCode.push_back(stoi(cleanedTokens[2]));

        // then there must be 2 registers
        } else {
            machineCode.push_back(map.find(map.REGISTERS, cleanedTokens[1]));
            machineCode.push_back(map.find(map.REGISTERS, cleanedTokens[2]));
            machineCode.push_back(stoi(cleanedTokens[3]));

        }

        machineCodeBits |= machineCode[0];
        machineCodeBits <<= 5;
        machineCodeBits |= machineCode[2];
        machineCodeBits <<= 5;
        machineCodeBits |= machineCode[1];
        machineCodeBits <<= 16;
        // convert to short to truncate the value to 16 bits
        machineCodeBits |= (uint16_t)(machineCode[3]);

    }


    return machineCodeBits;
}