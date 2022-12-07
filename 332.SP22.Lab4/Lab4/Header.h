#pragma once
#include <vector>
#include "game_piece.h"
#include <iostream>

//#include "game.h"

using namespace std;

//enum constants {
//	Boardx = 5,
//	Boardy = 5
//};


class GameBase {
protected:
	int dimX;
	int dimY;
	int numPieces;
	int numTurns;
	int displayLength;
	vector<game_piece> pieces;
	vector<game_piece> xMoves;
	vector<game_piece> oMoves;
	char display; //formerly char, move to string once its working
	char currentP; 
	char winner; //^
	//vector<game_piece> pcVec; //formerly x/omoves  now contains all
	static shared_ptr<GameBase> sharedP;
	friend std::ostream& operator<<(ostream& console, GameBase& tictac);
public:
	
	GameBase(int,int);
	virtual bool done()=0;
	virtual bool draw()=0;
	virtual int prompt(unsigned int x, unsigned int y); //purev???
	virtual int turn()=0;
	virtual int play()=0;
	//GameBase(int,int);
	//GameBase(GameBase &);
	virtual void print()=0;
	static std::shared_ptr<GameBase> gameOverwatch(int i, char* arr[]);
};



enum passed {
	success = 1, incorrectNoOfArguments = 2, wrongGame = 3, formattingError = 6, spaceUnavailable = 7, stringStreamError = 8, gameExited = 10, gameOverwatchError = 13
};

std::ostream& operator<<(std::ostream& console, GameBase& tictac);