#include <iostream>
#include <string>
#include <vector>
#include "Disassembler.h"
#include "Assembler.h"

using namespace std;

string inputText = "..\\input.txt";


template <typename T> void printVector(vector<T> vec) {
    int i = 0;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << "{" << i << ", " << *it << "}, ";
        i++;
    }
    cout << endl;
}

int main() {
//    ifstream inFile;
//    ofstream outFile;

    int addi = 0x2149ff9c;  // addi    $t1, $t2, -100
    int add = 0x014b4820;  // add  $t1, $t2, $t3
    int addi2 = 0x200803e8; // addi $t0, $zero, 1000
    int j = 0x08000001; // j 1

    string t1 = "addi $t1, $t2, -100";
    string t2 = "add $t1, $t2, $t3";
    string j1 = "j 100";

    Assembler a = Assembler();

    vector<int> tokens;
//    auto tokens = a.parseLine(t1);
//    printVector(tokens);

    tokens = a.parseLine(t2);
    printVector(tokens);
    tokens = a.parseLine(j1);
    printVector(tokens);


//    if (inFile.is_open()) {
//        string line;
//        while (getline(inFile, line)) {
//            printVector<string>(parseLine(line));
//        }
//    }


//    inFile.close();
//    outFile.close();
    return 0;
}

