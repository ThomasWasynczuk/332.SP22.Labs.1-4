// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include "Header.h" //also incl in game.h
#include <vector>
#include <fstream>
#include <string>
#include "TicTacToe.h"
#include "Gomoku.h"
//#include "game_piece.h"

using namespace std;


GameBase::GameBase(int boardx, int boardy) :
    dimX(boardx),
    dimY(boardy),
    display(' '),
    currentP('X'),
    winner(' '),
    //xMoves({}),
    //oMoves({})
    numPieces(boardx * boardy),
    numTurns(0),
    displayLength(1)
{
    //populate pcVec with empty pieces

}

//GameBase::GameBase(GameBase & base):
//    dimX(base.dimX),
//    dimY(base.dimY),
//    currentP(base.currentP),
//    numPieces(base.numPieces),
//    numTurns(base.numTurns),
//    displayLength(base.display)
//{
//    //populate pcVec with base.pcVec pieces
//}

TicTacToe::TicTacToe() :
    //dimX(5),
    //dimY(5),
    //currentP('X'),
    //numPieces(25),
    //xMoves({}),
    //oMoves({}),
    //winner(' ')
    //numTurns(base.numTurns),
    //displayLength(base.display)
    GameBase(5,5)
{}

Gomoku::Gomoku() :
    GameBase(19,19)
{}

std::ostream& operator<<(ostream& console, Gomoku& gomo);

std::ostream& operator<<(ostream& console, TicTacToe& tictac) {
    //    for (int i = 0; i < tictac.dimX - 1; i++) {
    
//    for (int i = 0; i < tictac.displayLength; i++)
    //^use display length to determine how much space to use between tiles
    //lab4.pdf item 9.^  --> also reccomended to use 'setw' stream manipulator and 'width' stream method
    if (tictac.pieces.empty()) {
        for (int i = 5 - 1; i >= 0; i--) {
            //        cout << i;
            for (int j = 0; j < 5; j++) {
                int k = 5 * i + j;
                game_piece emptyGuy;
                emptyGuy.xloc = 0;
                emptyGuy.yloc = 0;
                emptyGuy.team = ' ';
                tictac.pieces.push_back(emptyGuy);
            }
        }
    }
    for (int i = 5 - 1; i >= 0; i--) {
        cout << i;
        for (int j = 0; j < 5; j++) {
            int k = 5 * i + j;
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
    //if (argc != 2) {
    //    cout << "incorrectNoOfArguments" << endl;
    //    return 2;
    //}
    //string tt = "TicTacToe";
    //if (argv[1] != tt) {
    //    cout << "argunment 2 should read 'TicTacToe' instead of " << argv[1] << endl;
    //    return 3;
    //}
    //GameBase game;
    //return game.play();
    shared_ptr<GameBase> gO = GameBase::gameOverwatch(argc, argv); // was argv[]
    if (gO == 0) {
        return 13; //errno for gameOverwatch issues
    }
    else {
        int outcome = gO->play();
         //gotta destroy that^ somehow (#18.)
        //shared pt will be destroyed anyway
        return outcome;
    }
    
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
