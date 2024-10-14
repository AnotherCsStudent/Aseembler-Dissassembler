#include <iostream>
#include <string>
#include <vector>
#include "Disassembler.h"
#include "Assembler.h"
#include <bitset>
#include <fstream>

using namespace std;

/*
addi $t1, $t2, -100
add $t1, $t2, $t3
j 1
addi $t0, $zero, 1000

��I! HK  �
 */


string inputFilePath = "..\\data\\input.txt";
string outputFilePath = "..\\data\\output.txt";


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

//    int addi = 0x2149ff9c;  // addi    $t1, $t2, -100
//    int add = 0x014b4820;  // add  $t1, $t2, $t3
//    int addi2 = 0x200803e8; // addi $t0, $zero, 1000
//    int j = 0x08000001; // j 1
//
//    string t1 = "addi $t1, $t2, -100";
//    string t2 = "add $t1, $t2, $t3";
//    string j1 = "j 1";
//    string t3 = "addi $t0, $zero, 1000";
//
// ��I! HK  �

    inFile.open(inputFilePath);
    outFile.open(outputFilePath);


    if (inFile.is_open()) {
        cout << "inFile is open" << endl;
    } else {
        cerr << "INFILE NOT FOUND!" << endl;
        throw stderr;
    }

    if (outFile.is_open()) {
        cout << "outFile is open" << endl;
    } else {
        cerr << "OUTFILE NOT FOUND" << endl;
        throw stderr;
    }

    // cmd line prompting for which operation do to
    cout << endl;
    cout << "Do you want to: " << endl;
    cout << "(1) Assemble" << endl;
    cout << "(2) Disassemble" << endl;

    int mode = 0;
    do {
        cout << "Please select a mode (1 or 2)" << endl;
        cin >> mode;
    } while (!(mode == 1 || mode == 2));

    if (mode == 1) {
        cout << "Assembling!" << endl;


        string line = "";
        outFile.close();
        outFile.open(outputFilePath, std::ios::binary);
            Assembler assembler = Assembler();
            while (getline(inFile, line)) {
                int data = assembler.parseLine(line);
                outFile.write(reinterpret_cast<char *>(&data), sizeof(data));
                if (outFile.fail()) {
                    cout << "Brug" << endl;
                }
                cout << "Line written!" << endl;
            }


    } else {
        cout << "Disassembling" << endl;

        inFile.close();
        inFile.open(inputFilePath, std::ios::binary);
        Disassembler disassembler = Disassembler();

        int data = 0;
        while (inFile.read(reinterpret_cast<char*>(&data), sizeof(data))) {
            outFile << disassembler.disassembleChunk(data).c_str();
            outFile << endl;
        }
    }


    inFile.close();
    outFile.close();
    return 0;
}

