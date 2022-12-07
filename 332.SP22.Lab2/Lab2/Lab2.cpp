// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"
#include <vector>
#include <fstream>
#include <string>
#include "GamePiece.h"
#include "GameBoard.h"

using namespace std;

int inputstream(vector<string>& parsecode, char* inputfile) {
	string line;
	ifstream input;
	input.open(inputfile);
	if (input.is_open()) {
		while (getline(input, line)) {
			makeLower(line);
			cout << line << endl;
		}
		input.close();
		return success;
	}
	else {
		return usMsg("Lab2.exe", "unableToOpenFile", 2);
	}

}


int main(int argc, char* argv[]) {
	if (argc == acceptedNoOfArguments) {
		for (int i = 0; i < argc; ++i) {
			cout << argv[i] << endl;
		}
		vector<game_piece> a;
		//ifstream forReader;
		ifstream forBoard;

		unsigned int yco;
		unsigned int xco;
		forBoard.open(argv[1]);
		getDimensions(forBoard, yco, xco);
		for (int i = 0; i < (yco * xco); i++) {
			game_piece gp;
			gp.color = noColor;
			gp.name = "";
			gp.display = "";
			a.push_back(gp);
		}
		//inputstream(a, argv[1]);

		gamePieceReader(forBoard, a, yco, xco);
		printboard(a, xco, yco);
		return success;
	}
	else {
		return usMsg(argv[0], "incorrectNoOfArguments", 1);
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
