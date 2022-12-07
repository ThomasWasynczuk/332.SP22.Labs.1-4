#pragma once
#include <iostream>
#include <ostream>
#include "Header.h"
#include <vector>
#include <fstream>
#include <string>
//#include "game_piece.h"



using namespace std;

/// 
/// 6  7  8
/// 11 12 13
/// 16 17 18
///

bool Game::done() {
	//diaganal
	for (int i = 8; i > 5; i -= 2) {
		if (Game::pieces[i].team != ' ') {
			if ((Game::pieces[i].team == Game::pieces[12].team)) {
				if ((Game::pieces[i].team == Game::pieces[i + 12].team) || (Game::pieces[i].team == Game::pieces[i + 8].team)) {
					winner = Game::pieces[i].team;
					return true;
				}
			}

		}
	}
	//vertical
	for (int i = 6; i < 9; i++) {
		if (Game::pieces[i].team != ' ') {
			if ((Game::pieces[i].team == Game::pieces[i + 5].team) && (Game::pieces[i].team == Game::pieces[i + 10].team)) {
				winner = Game::pieces[i].team;
				return true;
			}
		}
	}
	//horizontal
	for (int i = 6; i < 17; i += 5) {
		if (Game::pieces[i].team != ' ') {
			if ((Game::pieces[i].team == Game::pieces[i + 1].team) && (Game::pieces[i].team == Game::pieces[i + 2].team)) {
				winner = Game::pieces[i].team;
				return true;
			}
		}
	}
	return false;
}

bool Game::draw() {
	if (this->done()) {
		return false;
	}
	if (xMoves.size() + oMoves.size() > 8) {
		return true;
	}
	else
		return false;
}


int Game::prompt(unsigned int x, unsigned int y) {
	cout << "enter coordinates into the command line like 'x,y' or type 'quit' to quit the program" << endl;
	string input_coords = "";
	//istringstream sleep(input_coords);
	getline(cin, input_coords);
	if (input_coords == "quit") {
		cout << "game terminated" << endl;
		cout << Game::xMoves.size() + Game::oMoves.size() << " total moves" << endl;
		exit(10);
		abort;
	}
	else if ((input_coords.size() != 3) || (input_coords[1] != ',')) {
		cout << "formatting error: please give coordinates in the format of 'x,y' where both coordinates are between 1 and 3" << endl;
		Game::prompt(x, y);
		return 6;
	}
	else {
		input_coords[1] = ' ';
	}
	std::istringstream iss(input_coords);
	if ((iss >> x) && (iss >> y)) {

		if ((x > 3) || (x < 1) || (y > 3) || (y < 1)) {
			cout << "formatting error: please give coordinates in the format of 'x,y' where both coordinates are between 1 and 3" << endl;
			Game::prompt(x, y);
			return 6;
		}

		int k = Boardx * y + x;

		Game::pieces[k].xloc = x;
		Game::pieces[k].yloc = y;

		if (Game::pieces[k].team != ' ') {
			cout << "please select an available space" << endl;
			prompt(x, y);
			return 7;
		}
		Game::pieces[k].team = currentP;
		game_piece tempPiece = Game::pieces[k];
		if (currentP == 'X') {
			xMoves.push_back(tempPiece);
		}
		else {
			oMoves.push_back(tempPiece);
		}
	}
	else {
		cout << "istringstream error, see line 78 of game.h" << endl;
		prompt(x, y);
		return 8;
	}
	return 1;
}

int Game::turn() {
	prompt(3, 3);
	cout << *this << endl << endl;
	//game_piece newMove;
	if (currentP == 'X') {
		cout << "player X: ";
		for (unsigned int i = 0; i < xMoves.size(); i++) {
			//crashes here
			cout << xMoves[i].xloc << ", " << xMoves[i].yloc << "; ";
		}
		cout << endl;
		currentP = 'O';
	}
	else {
		for (unsigned int i = 0; i < oMoves.size(); i++) {
			//crashes here
			cout << oMoves[i].xloc << ", " << oMoves[i].yloc << "; ";
		}
		cout << endl;
		currentP = 'X';
	}
	return 1;
}

int Game::play() {
	cout << *this << endl;
	while ((!done()) && (!draw())) {
		turn();
	}
	if (done()) {
		cout << winner << " wins!" << endl;
		return 1;
	}
	if (draw()) {
		cout << "it's a draw!" << endl;
		return 1;
	}
	else return 10;
}