#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

enum arguments {
	programName = 0, inputFile = 1, argCount = 3
};
enum errors {
	success = 0, incorrectNumArgs = 1, cantOpenFile = 2
};
int usageMessage(const char* limon) {
    cout << "Woah there, silly goose! You've got to type a space after 'Lab1.exe' then type the name of your input file" << endl;
    cout << "you can use 'input_file1.txt' if you don't have one" << endl;
    cout << "Make sure your input file is in the Lab1 debug folder!";
    cout << "error location: " << limon << endl;
    return 1;
}
int parse(vector<string>& textVec, char* inputFile) {
    string temp;
    ifstream reader;
    reader.open(inputFile);
    if (reader.is_open()) {
        while (reader >> temp) {
            textVec.push_back(temp);

        }
        reader.close();
    }
    else {
        cout << "ifstream could not open the file" << endl;
        return cantOpenFile;
    }
    //cout << textVec;
    return success;
}

