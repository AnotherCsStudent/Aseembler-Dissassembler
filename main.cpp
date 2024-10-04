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

string clean(string inputString) {
    string returnString;

    // iterator through the whole string
    int i = 0;

    // iterate past the leading spaces
    bool spaces = true;
    while (spaces && i < inputString.length()) {
        if (inputString[i] == ' ') {
            i++;
        } else {
            spaces = false;
        }
    }

    while (i < inputString.length()) {
        returnString += inputString[i];
        i++;
    }

    return returnString;

}


int main() {
    ifstream inFile;
    ofstream outFile;
    inFile.open(inputText);

    string string1 = "";
    string string2 = " ";
    string string3 = "test";
    string string4 = " test ";
    string string5 = " wouldn't you  like to know";

    cout << "string1: " << clean(string1) << endl;
    cout << "string2: " << clean(string2) << endl;
    cout << "string3: " << clean(string3) << endl;
    cout << "string4: " << clean(string4) << endl;
    cout << "string5: " << clean(string5) << endl;


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

//    if (inFile.is_open()) {
//        string line;
//        while (getline(inFile, line)) {
//            cout << line << endl;
//        }
//    }


    inFile.close();
    outFile.close();
    return 0;
}
