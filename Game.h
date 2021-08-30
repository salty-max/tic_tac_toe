//
// Created by Maxime Blanc on 30/08/2021.
//

#pragma once
#include "Player.h"

class Game {
public:
  void playGame();

private:
  char _board[3][3]{};
  static void printTitle();
  void printBoard();
  void clearBoard();
  static int getXCoord();
  static int getYCoord();
  bool placeMarker(int x, int y, const Player &player);
  bool checkForVictory(char marker);
};