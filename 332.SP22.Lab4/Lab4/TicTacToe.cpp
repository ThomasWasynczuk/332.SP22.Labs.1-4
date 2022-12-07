#include <iostream>
#include <ostream>
#include "Header.h"
#include "TicTacToe.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

bool TicTacToe::done() {
	//diaganal
	for (int i = 8; i > 5; i -= 2) {
		if (TicTacToe::pieces[i].team != ' ') {
			if ((TicTacToe::pieces[i].team == TicTacToe::pieces[12].team)) {
				if ((TicTacToe::pieces[i].team == TicTacToe::pieces[i + 12].team) || (TicTacToe::pieces[i].team == TicTacToe::pieces[i + 8].team)) {
					winner = TicTacToe::pieces[i].team;
					return true;
				}
			}

		}
	}
	//vertical
	for (int i = 6; i < 9; i++) {
		if (TicTacToe::pieces[i].team != ' ') {
			if ((TicTacToe::pieces[i].team == TicTacToe::pieces[i + 5].team) && (TicTacToe::pieces[i].team == TicTacToe::pieces[(int)i + 10].team)) {
				winner = TicTacToe::pieces[i].team;
				return true;
			}
		}
	}
	//horizontal
	for (int i = 6; i < 17; i += 5) {
		if (TicTacToe::pieces[i].team != ' ') {
			if ((TicTacToe::pieces[i].team == TicTacToe::pieces[i + 1].team) && (TicTacToe::pieces[i].team == TicTacToe::pieces[(int)i + 2].team)) {
				winner = TicTacToe::pieces[i].team;
				return true;
			}
		}
	}
	return false;
}

bool TicTacToe::draw() {
	if (this->done()) {
		return false;
	}
	if (xMoves.size() + oMoves.size() > 8) {
		return true;
	}
	else
		return false;
}

int TicTacToe::turn() {
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

int TicTacToe::play() {
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

int TicTacToe::prompt(unsigned int x, unsigned int y) {
	cout << "enter coordinates into the command line like 'x,y' or type 'quit' to quit the program" << endl;
	string input_coords = "";
	//istringstream sleep(input_coords);
	getline(cin, input_coords);
	if (input_coords == "quit") {
		cout << "game terminated" << endl;
		cout << GameBase::xMoves.size() + GameBase::oMoves.size() << " total moves" << endl;
		exit(10);
		abort;
	}
	else if ((input_coords.size() != 3) || (input_coords[1] != ',')) {
		cout << "formatting error: please give coordinates in the format of 'x,y' where both coordinates are between 1 and 3" << endl;
		GameBase::prompt(x, y);
		return 6;
	}
	else {
		input_coords[1] = ' ';
	}
	std::istringstream iss(input_coords);

	if ((iss >> x) && (iss >> y)) {

		if ((x > 3) || (x < 1) || (y > 3) || (y < 1)) {
			cout << "formatting error: please give coordinates in the format of 'x,y' where both coordinates are between 1 and 3" << endl;
			GameBase::prompt(x, y);
			return 6;
		}

		int k = 5 * y + x;

		GameBase::pieces[k].xloc = x;
		GameBase::pieces[k].yloc = y;

		if (GameBase::pieces[k].team != ' ') {
			cout << "please select an available space" << endl;
			prompt(x, y);
			return 7;
		}
		GameBase::pieces[k].team = currentP;
		game_piece tempPiece = GameBase::pieces[k];
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

void TicTacToe::print() {
	//print the game!
	cout << *this << endl;
}