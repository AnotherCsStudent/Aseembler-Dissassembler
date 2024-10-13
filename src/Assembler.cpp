#include "Assembler.h"
#include <iostream>
#include <vector>
#include "AssemblerMaps.h"
#include <cmath>

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

string Assembler::strip(string inputString , char deleteChar) {
    string returnString = "";

    for (int i = 0; i < inputString.length(); i++) {
        if (inputString[i] != deleteChar) {
            returnString += inputString[i];
        }
    }

    return returnString;

}

vector<int> Assembler::parseLine(string inputString) {
    vector<string> returnTokens = split(inputString, ' ');
    vector<string> cleanedTokens = vector<string>();
    AssemblerMaps map = AssemblerMaps();

    // clean the commas out of the tokens
    for (int i = 0; i < returnTokens.size(); i++) {
        cleanedTokens.push_back(strip(returnTokens[i], ','));
    }

    vector<int> machineCode = vector<int>();
    int initialToken = map.find(map.OPCODES, cleanedTokens[0]);

    printVector(cleanedTokens);


    // r-type instructions
    if (initialToken == 0b000000) {
        machineCode.push_back(initialToken);
        int i = 0;
        cout << cleanedTokens.size();
        for (i = 1; i < cleanedTokens.size(); i++) {
            cout << cleanedTokens.size();
            machineCode.push_back(map.find(map.REGISTERS, cleanedTokens[i]));
        }
        // there are 4 register slots, and unfilled ones need to be filled with blank registers
        for (int j = 0; i < 4; i++) {
            machineCode.push_back(0b00000);
        }
        machineCode.push_back(map.find(map.FUNC_CODES, cleanedTokens[0]));

    } else if (initialToken == 0b000010 || initialToken == 0b000011) {
        machineCode.push_back(map.find(map.OPCODES, cleanedTokens[0]));
        int literalValue = stoi(cleanedTokens[1]);
        machineCode.push_back(literalValue);
    } else {
        machineCode.push_back(map.find(map.OPCODES, cleanedTokens[0]));
    }


    return machineCode;
}