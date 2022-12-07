#pragma once
//#pragma twice
#pragma warning(disable: 4996)
#include <iostream>
#include "Header.h"
#include "GamePiece.cpp"
#include <vector>
#include <fstream>
#include <string>

using namespace std;
enum piece_color {
	noColor = 0, invalidColor = 1, red = 2, black = 3, white = 4, blue = 5
};

struct game_piece {
	piece_color color;
	string name;
	string display;
};


string lowercaseColor(piece_color color) {
	string getColor[] = { "noColor", "invalidColor", "red", "black", "white", "blue"};
	makeLower(getColor[color]);
	return getColor[color];
}

piece_color getEnumFromString(string s) {
	string q = s;
	makeLower(q);
	if (q == "red") {
		return red;
	}
	if (q == "black") {
		return black;
	}
	if (q == "white") {
		return white;
	}
	if (q == "blue") {
		return blue;
	}
	if ((q == "nocolor")||(q==" ")) {
		return noColor;
	}
	else {
		return invalidColor;
	}
}