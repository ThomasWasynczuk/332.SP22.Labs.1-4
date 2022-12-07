#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include "Header.h"
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;


enum ArIndices
{
	programName = 0, fileName = 1, acceptedNoOfArguments = 2
};

enum Passed
{
	success = 0, incorrectNoOfArguments = 1, unableToOpenFile = 2, invalidDimensions = 3
};

int usMsg(const string fileName, string errorType, int errorNum) {
	cout << "program name:" << fileName << endl;
	cout << "error: " + errorType;
	if (errorNum == 1) {
		cout << " type 'Lab2.exe' , space, then the name of the input file" << endl;
	}
	if (errorNum == 2) {
		cout << " make sure your input file is spelled correctly and located in Lab2's 'Debug' folder" << endl;
	}
	return errorNum;
}

void makeLower(string& s) {
	int lengthp1 = s.length() + 1;
	char* chap = new char[lengthp1];
	strcpy(chap, s.c_str());
	for (int i = 0; i < lengthp1 - 1; i++) {
		if (((int)chap[i] > 64) && (int)chap[i] < 91) {
			chap[i] = (int)chap[i] + 32;
			s.at(i) = chap[i];
		}
	}
	delete[] chap;
	return;
}
