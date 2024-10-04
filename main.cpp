#include <iostream>
#include <string>
#include <fstream>
#include <vector>
// #include <windows.h>

using namespace std;

string inputText = "..\\input.txt";

//void test() {
//    char path[MAX_PATH];
//    if (GetModuleFileName(NULL, path, MAX_PATH)) {
//        std::cout << "Program is being executed from: " << path << std::endl;
//    } else {
//        std::cerr << "Error finding the path." << std::endl;
//    }
//}

vector<string> split(string inputString, char delimiter) {
    vector<char> buffer = vector<char>();
    vector<string> tokens = vector<string>();


    for (int i = 0; i < inputString.length(); i++) {
        cout << i;
    }

    int initialIndex = 0;
    int endIndex = 0;
    for (string::iterator it = inputString.begin(); it != inputString.end(); it++) {
        if (*it == delimiter) {
            tokens.push_back(inputString.substr(initialIndex, endIndex - initialIndex  ));
            initialIndex = endIndex + 1;
        }
        endIndex++;
    }

    // flush the rest of the string into the tokens list
    tokens.push_back(inputString.substr(initialIndex, endIndex));

    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
        cout << it->c_str() << endl;
    }

    return tokens;
}

int main() {
    ifstream inFile;
    ofstream outFile;
    inFile.open(inputText);


    string splittable = "This is a splittable string";
    split(splittable, ' ');


    inFile.close();
    outFile.close();
    return 0;
}
