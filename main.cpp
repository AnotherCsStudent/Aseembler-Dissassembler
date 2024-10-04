#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "TokenMap.h"
// #include <windows.h>

using namespace std;

string inputText = "..\\input.txt";

// splits a string based on a delimiter character
vector<string> split(string inputString, char delimiter) {
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

string strip(string inputString , char deleteChar) {
    string returnString = "";

    for (int i = 0; i < inputString.length(); i++) {
        if (inputString[i] != deleteChar) {
            returnString += inputString[i];
        }
    }

    return returnString;

}

vector<string> parseLine(string inputString) {
    vector<string> returnTokens = split(inputString, ' ');

    for (vector<string>::iterator it = returnTokens.begin(); it != returnTokens.end(); it++) {
        *it = strip(*it, ',');
    }

    return returnTokens;
}

template <typename T> void printVector(vector<T> vec) {
    int i = 0;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << "{" << i << ", " << *it << "}, ";
        i++;
    }
    cout << endl;
}

int main() {
    ifstream inFile;
    ofstream outFile;
    inFile.open(inputText);

    printVector<string>(parseLine("add $t1, $t2"));


//    TokenMap opcodes;
//
//    try {
//        opcodes = TokenMap("MIPS-OPCODES");
//    } catch (runtime_error e){
//        cout << e.what();
//        return -1;
//    }
//
//    cout << opcodes.find("test");

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            printVector<string>(parseLine(line));
        }
    }


    inFile.close();
    outFile.close();
    return 0;
}
