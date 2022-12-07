#pragma once
#include <iostream>

class Gomoku : public GameBase {//lecture 12 slides
public://get tic tac toe working as inherited class
	Gomoku();//constructor calls gamebase constructor
	friend std::ostream& operator<<(ostream& console, GameBase& gomo);
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual int prompt(unsigned int x, unsigned int y);
	int play();
	void print();
};