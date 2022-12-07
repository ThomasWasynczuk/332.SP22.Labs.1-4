#pragma once
#include <iostream>

class TicTacToe : public GameBase {//lecture 12 slides
public://get tic tac toe working as inherited class
	TicTacToe();//constructor calls gamebase constructor
	friend std::ostream& operator<<(ostream& console, TicTacToe& tictac);
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	int prompt(unsigned int x, unsigned int y);
	int play();
	void print();
};