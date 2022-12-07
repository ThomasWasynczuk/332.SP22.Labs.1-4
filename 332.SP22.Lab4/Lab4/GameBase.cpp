#pragma once
#include <iostream>
#include <ostream>
#include "Header.h"
#include "TicTacToe.h"
#include "Gomoku.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
//#include "game_piece.h"


using namespace std;


/// 
/// 6  7  8
/// 11 12 13
/// 16 17 18
///

/*
gameOverwatch() will decide which game to play based on our input
	takes responsibilities of lab3's main ftn
*/

shared_ptr<GameBase> GameBase::gameOverwatch(int i, char* a[]) {
	shared_ptr<GameBase> emptyP = 0;
	if (i != 2) {
		cout << "wrong number of args" << endl;
	}
	else {
		string whichGame = a[1];
		if (whichGame == "TicTacToe") {
			shared_ptr<GameBase> TicTacToe_game = make_shared<TicTacToe>();
			return TicTacToe_game;
		}
		else if (whichGame == "Gomoku") {
			//cout<<setw(19);  
			//^this didnt work but we need an alternative to make pieces line up with board coords
			shared_ptr<GameBase> Gomoku_game = make_shared<Gomoku>();
			return Gomoku_game;
		}
		else {
			cout << "arg 2 should be either 'TicTacToe' or 'Gomoku'" << endl;
			return emptyP;
		}
	}
}

/*
Below defines GameBase:
	done(), draw(), prompt(), turn(), play(), and print()
*/


bool GameBase::done() {
	//diaganal
	for (int i = 8; i > 5; i -= 2) {
		if (GameBase::pieces[i].team != ' ') {
			if ((GameBase::pieces[i].team == GameBase::pieces[12].team)) {
				if ((GameBase::pieces[i].team == GameBase::pieces[i + 12].team) || (GameBase::pieces[i].team == GameBase::pieces[i + 8].team)) {
					winner = GameBase::pieces[i].team;
					return true;
				}
			}

		}
	}
	//vertical
	for (int i = 6; i < 9; i++) {
		if (GameBase::pieces[i].team != ' ') {
			if ((GameBase::pieces[i].team == GameBase::pieces[i + 5].team) && (GameBase::pieces[i].team == GameBase::pieces[i + 10].team)) {
				winner = GameBase::pieces[i].team;
				return true;
			}
		}
	}
	//horizontal
	for (int i = 6; i < 17; i += 5) {
		if (GameBase::pieces[i].team != ' ') {
			if ((GameBase::pieces[i].team == GameBase::pieces[i + 1].team) && (GameBase::pieces[i].team == GameBase::pieces[i + 2].team)) {
				winner = GameBase::pieces[i].team;
				return true;
			}
		}
	}
	return false;
}

bool GameBase::draw() {
	if (this->done()) {
		return false;
	}
	if (xMoves.size() + oMoves.size() > 8) {
		return true;
	}
	else
		return false;
}


int GameBase::prompt(unsigned int x, unsigned int y) {
	return this->prompt(x, y);
	//cout << "enter coordinates into the command line like 'x,y' or type 'quit' to quit the program" << endl;
	//string input_coords = "";
	////istringstream sleep(input_coords);
	//getline(cin, input_coords);
	//if (input_coords == "quit") {
	//	cout << "game terminated" << endl;
	//	cout << GameBase::xMoves.size() + GameBase::oMoves.size() << " total moves" << endl;
	//	exit(10);
	//	abort;
	//}
	//else if ((input_coords.size() != 3) || (input_coords[1] != ',')) {
	//	cout << "formatting error: please give coordinates in the format of 'x,y' where both coordinates are between 1 and 3" << endl;
	//	GameBase::prompt(x, y);
	//	return 6;
	//}
	//else {
	//	input_coords[1] = ' ';
	//}
	//std::istringstream iss(input_coords);

	//if ((iss >> x) && (iss >> y)) {

	//	if ((x > 3) || (x < 1) || (y > 3) || (y < 1)) {
	//		cout << "formatting error: please give coordinates in the format of 'x,y' where both coordinates are between 1 and 3" << endl;
	//		GameBase::prompt(x, y);
	//		return 6;
	//	}

	//	int k = 5 * y + x;

	//	GameBase::pieces[k].xloc = x;
	//	GameBase::pieces[k].yloc = y;

	//	if (GameBase::pieces[k].team != ' ') {
	//		cout << "please select an available space" << endl;
	//		prompt(x, y);
	//		return 7;
	//	}
	//	GameBase::pieces[k].team = currentP;
	//	game_piece tempPiece = GameBase::pieces[k];
	//	if (currentP == 'X') {
	//		xMoves.push_back(tempPiece);
	//	}
	//	else {
	//		oMoves.push_back(tempPiece);
	//	}
	//}
	//else {
	//	cout << "istringstream error, see line 78 of game.h" << endl;
	//	prompt(x, y);
	//	return 8;
	//}
	//return 1;
}

int GameBase::turn() {
	return this->turn();
	////if(GameBase::dimX == 3 && GameBase::dimY == 3){}
	//prompt(3, 3);
	//cout << *this << endl << endl;
	////game_piece newMove;
	//if (currentP == 'X') {
	//	cout << "player X: ";
	//	for (unsigned int i = 0; i < xMoves.size(); i++) {
	//		//crashes here
	//		cout << xMoves[i].xloc << ", " << xMoves[i].yloc << "; ";
	//	}
	//	cout << endl;
	//	currentP = 'O';
	//}
	//else {
	//	for (unsigned int i = 0; i < oMoves.size(); i++) {
	//		//crashes here
	//		cout << oMoves[i].xloc << ", " << oMoves[i].yloc << "; ";
	//	}
	//	cout << endl;
	//	currentP = 'X';
	//}
	//return 1;
}

int GameBase::play() {
	return this->play();
	//cout << *this << endl;
	//while ((!done()) && (!draw())) {
	//	turn();
	//}
	//if (done()) {
	//	cout << winner << " wins!" << endl;
	//	return 1;
	//}
	//if (draw()) {
	//	cout << "it's a draw!" << endl;
	//	return 1;
	//}
	//else return 10;
}

void GameBase::print() {
	//print the game!

}





/*
Above defines GameBase:


Below once defined TicTacToe:
	done(), draw(), turn(), play(), print()
-- but no longer, they're in tictactoe.cpp
*/


