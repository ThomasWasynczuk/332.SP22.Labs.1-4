#pragma once
#include <vector>
#include "game_piece.h"
//#include "game.h"

using namespace std;

enum constants {
	Boardx = 5,
	Boardy = 5
};

class Game {
private:
	int dimX;
	int dimY;
	char display;
	char currentP;
	char winner;
	vector<game_piece> xMoves;
	vector<game_piece> oMoves;

public:
	vector<game_piece> pieces;
	bool done();
	bool draw();
	int prompt(unsigned int x, unsigned int y);
	int turn();
	int play();
	Game();


	friend ostream& operator <<(ostream& console, Game& tictac);

};

enum passed {
	success = 1, incorrectNoOfArguments = 2, wrongGame = 3, formattingError = 6, spaceUnavailable = 7, stringStreamError = 8, gameExited = 10
};