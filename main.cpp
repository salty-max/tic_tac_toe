#include "Game.h"
#include <iostream>

int main() {
  char input;
  bool isDone = false;
  Game game;

  while (!isDone) {
    game.playGame();
    std::cout << "Would you like to play again (Y/N): ";
    std::cin >> input;

    if (input == 'N' || input == 'n') {
      isDone = true;
    }
  }

  getchar();
  return 0;
}
