#pragma once
//#pragma twice
#pragma warning(disable: 4996)
#include <iostream>
#include "Header.h"
#include "GamePiece.cpp"
#include "GamePiece.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int getDimensions(ifstream& input_stream, unsigned int& a, unsigned int& b) {
	string line;
	if (getline(input_stream, line)) {
		istringstream ss(line);
		if ((ss >> a) && (ss >> b)) {
			return success;
		}
		else {
			usMsg("Gameboard.h", "invalidDimensions", 3);
			return invalidDimensions;
		}
	}
	else {
		usMsg("Gameboard.h", "unableToOpenFile", 2);
		return unableToOpenFile;
	}

}

int gamePieceReader(ifstream& input_stream, vector<game_piece>& pieces, unsigned int a, unsigned int b) {
	string line;
	string team;
	string piece;
	string display;
	unsigned int xco;
	unsigned int yco;
	while (getline(input_stream, line)) {
		istringstream ss(line);
		if ((ss >> team) && (ss >> piece) && (ss >> display) && (ss >> xco) && (ss >> yco)) {
			piece_color team_enum = getEnumFromString(team);
			if ((yco >= a) || (xco >= b) || (team_enum == invalidColor) || (team_enum == noColor)) {
				continue;
			}

			int index = a * yco + xco;
			pieces[index].color = team_enum;
			pieces[index].name = piece;
			pieces[index].display = display;
			//cout << "1" << endl;
		}
	}
	return success;
}

void printboard(const vector<game_piece>& pieces, unsigned int xco, unsigned int yco) {
	for (int i = (yco - 1); i > -1; i--) {
		for (int j = 0; j < xco; j++) {
			int place = yco * i + j;
			cout << pieces[place].display << " ";
		}
		cout << endl;
	}
	return;
}