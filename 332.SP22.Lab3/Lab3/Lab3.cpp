// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
//#include "Header.h"
#include <vector>
#include <fstream>
#include <string>
//#include "game_piece.h"
#include "game.h"

using namespace std;


Game::Game() :
    dimX(Boardx),
    dimY(Boardy),
    display(' '),
    currentP('X'),
    winner(' '),
    xMoves({}),
    oMoves({})
{}

ostream& operator << (ostream& console, Game& tictac) {
    //    for (int i = 0; i < tictac.dimX - 1; i++) {
    if (tictac.pieces.empty()) {
        for (int i = Boardx - 1; i >= 0; i--) {
            //        cout << i;
            for (int j = 0; j < Boardy; j++) {
                int k = Boardx * i + j;
                game_piece emptyGuy;
                emptyGuy.xloc = 0;
                emptyGuy.yloc = 0;
                emptyGuy.team = ' ';
                tictac.pieces.push_back(emptyGuy);
            }
        }
    }
    for (int i = Boardx - 1; i >= 0; i--) {
        cout << i;
        for (int j = 0; j < Boardy; j++) {
            int k = Boardx * i + j;
            tictac.pieces[k].xloc = j;
            tictac.pieces[k].yloc = i;
            cout << tictac.pieces[k].team << ' ';

        }
        cout << endl;
    }
    cout << " 0 1 2 3 4";


    return console;
}




int main(int argc, char* argv[])
{
    if (argc != 2) {
        cout << "incorrectNoOfArguments" << endl;
        return 2;
    }
    string tt = "TicTacToe";
    if (argv[1] != tt) {
        cout << "argunment 2 should read 'TicTacToe' instead of " << argv[1] << endl;
        return 3;
    }
    Game game;
    return game.play();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
