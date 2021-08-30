//
// Created by Maxime Blanc on 30/08/2021.
//

#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() {
    clearBoard();
}

void Game::printBoard() {
    cout << endl;
    cout << " |1|2|3|\n";

    for (int i = 0; i < 3; i++) {
        cout << "--------" << endl;
        cout << i + 1 << "|" << _board[i][0] << "|" << _board[i][1] << "|" << _board[i][2] << "|" << endl;
    }

    cout << "--------" << endl;
};

void Game::clearBoard() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            _board[row][col] = '.';
        }
    }
}
