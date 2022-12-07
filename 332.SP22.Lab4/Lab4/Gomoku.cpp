#include <iostream>
#include <ostream>
#include "Header.h"
#include "Gomoku.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

bool Gomoku::done()
{
	size_t size = Gomoku::pieces.size();
	//int toWin = 5;
	//int ct = 1;
	for (unsigned __int64 i = 1; i < 325; i++) {
		if (Gomoku::pieces[i].team != ' ') {
			if (Gomoku::pieces[i].team == Gomoku::pieces[static_cast<__int64>(i + 1)].team && Gomoku::pieces[static_cast<__int64>(i + 1)].team == Gomoku::pieces[static_cast<__int64>(i + 2)].team && Gomoku::pieces[static_cast<__int64>(i + 2)].team == Gomoku::pieces[static_cast<__int64>(i + 3)].team && Gomoku::pieces[static_cast<__int64>(i + 3)].team == Gomoku::pieces[static_cast<__int64>(i + 4)].team) {
				winner = Gomoku::pieces[i].team;
				return true;
			}
			if (Gomoku::pieces[i].team == Gomoku::pieces[static_cast<__int64>(i + 20)].team && Gomoku::pieces[static_cast<__int64>(i + 20)].team == Gomoku::pieces[static_cast<__int64>(i + 40)].team && Gomoku::pieces[static_cast<__int64>(i + 40)].team == Gomoku::pieces[static_cast<__int64>(i + 60)].team && Gomoku::pieces[static_cast<__int64>(i + 60)].team == Gomoku::pieces[static_cast<__int64>(i + 80)].team) {
				winner = Gomoku::pieces[i].team;
				return true;
			}
			if (Gomoku::pieces[i].team == Gomoku::pieces[static_cast<__int64>(i + 21)].team && Gomoku::pieces[static_cast<__int64>(i + 21)].team == Gomoku::pieces[static_cast<__int64>(i + 42)].team && Gomoku::pieces[static_cast<__int64>(i + 42)].team == Gomoku::pieces[static_cast<__int64>(i + 63)].team && Gomoku::pieces[static_cast<__int64>(i + 63)].team == Gomoku::pieces[static_cast<__int64>(i + 84)].team) {
				winner = Gomoku::pieces[i].team;
				return true;
			}
			if (Gomoku::pieces[i].team == Gomoku::pieces[static_cast<__int64>(i + 19)].team && Gomoku::pieces[static_cast<__int64>(i + 19)].team == Gomoku::pieces[static_cast<__int64>(i + 38)].team && Gomoku::pieces[static_cast<__int64>(i + 38)].team == Gomoku::pieces[static_cast<__int64>(i + 57)].team && Gomoku::pieces[static_cast<__int64>(i + 57)].team == Gomoku::pieces[static_cast<__int64>(i + 76)].team) {
				winner = Gomoku::pieces[i].team;
				return true;
			}
		}
	}
	return false;
}

bool Gomoku::draw()
{
    if (this->done()) {
        return false;
    }
    if (xMoves.size() + oMoves.size() > 324) {
        return true;
    }
    else
        return false;
}

int Gomoku::turn()
{
	prompt(19, 19);
	cout << *this << endl << endl;
	//game_piece newMove;
	if (currentP == 'B') {
		cout << "player B: ";
		for (unsigned int i = 0; i < xMoves.size(); i++) {
			//crashes here
			cout << xMoves[i].xloc << ", " << xMoves[i].yloc << "; ";
		}
		cout << endl;
		currentP = 'W';
	}
	else {
		cout << "player W: ";
		for (unsigned int i = 0; i < oMoves.size(); i++) {
			//crashes here
			cout << oMoves[i].xloc << ", " << oMoves[i].yloc << "; ";
		}
		cout << endl;
		currentP = 'B';
	}
	return 1;
}

int Gomoku::prompt(unsigned int x, unsigned int y)
{
	cout << "enter coordinates into the command line like 'x,y' or type 'quit' to quit the program" << endl;
	string input_coords = "";
	//istringstream sleep(input_coords);
	getline(cin, input_coords);
	if (input_coords == "quit") {
		cout << "game terminated" << endl;
		cout << GameBase::xMoves.size() + GameBase::oMoves.size() << " total moves" << endl;
		exit(10);
		abort();
	}
	else if ((input_coords.size() < 3) || (input_coords.size() > 5)) {
		cout << "formatting error: please give coordinates in the format of 'x,y' where both coordinates are between 1 and 19 ../ Gomoku.cpp ln.84" << endl;
		GameBase::prompt(x, y);
		return 6;
	}
	else if (input_coords[1] == ',') {
		input_coords[1] = ' ';
	}
	else if (input_coords[2] == ',') {
		input_coords[2] = ' ';
	}

	std::istringstream iss(input_coords);

	if ((iss >> x) && (iss >> y)) {

		if ((x > 19) || (x < 1) || (y > 19) || (y < 1)) {
			cout << "formatting error: please give coordinates in the format of 'x,y' where both coordinates are between 1 and 19" << endl;
			GameBase::prompt(x, y);
			return 6;
		}

		int k = 20 * y + x;

		GameBase::pieces[k].xloc = x;
		GameBase::pieces[k].yloc = y;

		if (GameBase::pieces[k].team != ' ') {
			cout << "please select an available space" << endl;
			prompt(x, y);
			return 7;
		}
		GameBase::pieces[k].team = currentP;
		game_piece tempPiece = GameBase::pieces[k];
		if (currentP == 'B') {
			xMoves.push_back(tempPiece);
		}
		else {
			oMoves.push_back(tempPiece);
		}
	}
	else {
		cout << "istringstream error, see prompt ftn in Gomoku.cpp" << endl;
		prompt(x, y);
		return 8;
	}
	return 1;
}

int Gomoku::play()
{
    cout << *this << endl;
	this->currentP = 'B';
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

void Gomoku::print()
{
    cout << *this << endl;
}

std::ostream& operator<<(ostream& console, GameBase& gomo)
{
	cout << endl;
    if (gomo.pieces.empty()) {
        for (int i = 20 ; i > 0; i--) {
            for (int j = 0; j < 20; j++) {
                int k = 20 * i + j;
                game_piece emptyGuy;
                emptyGuy.xloc = 0;
                emptyGuy.yloc = 0;
				emptyGuy.team = ' ';//(k%10)+48;
                gomo.pieces.push_back(emptyGuy);
            }
        }
    }
    for (int i = 20 -1; i > 0; i--) {
		
		cout << setw(3);
        cout << i;
        for (int j = 1; j < 20; j++) {
            int k = 20 * i + j;
            gomo.pieces[k].xloc = j;
            gomo.pieces[k].yloc = i;
			cout << setw(3);
			cout << gomo.pieces[k].team;// << ' ';
        }
		cout << endl;
    }
	cout << setw(3);
	cout << ' ';
    for (int i = 1; i < 20; i++) {
		cout << setw(3);
        //cout << ' ' << i;
		cout << i;
    }
    return console;
}
