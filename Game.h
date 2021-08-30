//
// Created by Maxime Blanc on 30/08/2021.
//

#pragma once

class Game {
public:
    Game();
    void printBoard();
    void clearBoard();

private:
    char _board[3][3];
};