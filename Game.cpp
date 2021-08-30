//
// Created by Maxime Blanc on 30/08/2021.
//

#include "Game.h"
#include "Player.h"
#include <iostream>

void Game::playGame() {
  clearBoard();

  Player player1(1);
  Player player2(2);

  bool playing = true;

  int x, y;

  int turn = 0;

  printTitle();

  player1.setName();
  player1.setMarker();
  player2.setName();
  player2.setMarker();

  Player currentPlayer = player1;

  std::cout << std::endl;

  while (playing) {
    std::cout << "\033[1;35m" << currentPlayer.getName() << "'s turn!\033[0m"
              << std::endl;

    printBoard();
    x = getXCoord();
    y = getYCoord();

    if (!placeMarker(x, y, currentPlayer)) {
      std::cout << "\033[1;31mThis spot is occupied!\033[0m" << std::endl;
    } else {
      turn++;
      if (checkForVictory(currentPlayer.getMarker())) {
        std::cout << "The game is over!" << std::endl;
        std::cout << "\033[1;32m" << currentPlayer.getName() << " wins!\033[0m"
                  << std::endl;
        printBoard();
        playing = false;
      } else if (turn == 9) {
        std::cout << "\033[1;33mIt's a tie!\033[0m" << std::endl;
        playing = false;
      }

      // Switch player
      if (currentPlayer.getId() == player1.getId()) {
        currentPlayer = player2;
      } else {
        currentPlayer = player1;
      }
    }

    std::cout << std::endl;
  }
}

void Game::printTitle() {
  std::cout << "\033[1;35m*********" << std::endl;
  std::cout << "* T I C *" << std::endl;
  std::cout << "* T A C *" << std::endl;
  std::cout << "* T O E *" << std::endl;
  std::cout << "*********\033[0m" << std::endl;
}

void Game::printBoard() {
  std::cout << std::endl;
  std::cout << " |1|2|3|\n";

  for (int i = 0; i < 3; i++) {
    std::cout << "--------" << std::endl;
    std::cout << i + 1 << "|" << _board[i][0] << "|" << _board[i][1] << "|"
              << _board[i][2] << "|" << std::endl;
  }

  std::cout << "--------" << std::endl;
}

void Game::clearBoard() {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      _board[row][col] = '.';
    }
  }
}

int Game::getXCoord() {
  int x;
  bool isInputBad = true;

  while (isInputBad) {
    std::cout << "Enter the X coordinate: ";
    std::cin >> x;

    if (x < 1 || x > 3) {
      std::cout << "Invalid coordinate!" << std::endl;
    } else {
      isInputBad = false;
    }
  }

  return x - 1;
}

int Game::getYCoord() {
  int y;
  bool isInputBad = true;

  while (isInputBad) {
    std::cout << "Enter the Y coordinate: ";
    std::cin >> y;

    if (y < 1 || y > 3) {
      std::cout << "Invalid coordinate!" << std::endl;
    } else {
      isInputBad = false;
    }
  }

  return y - 1;
}

bool Game::placeMarker(int x, int y, const Player &player) {
  if (_board[y][x] != '.') {
    return false;
  }

  _board[y][x] = player.getMarker();
  return true;
}

bool Game::checkForVictory(char marker) {
  // Check the rows
  for (int row = 0; row < 3; row++) {
    if (_board[row][0] == marker && _board[row][0] == _board[row][1] &&
        _board[row][1] == _board[row][2]) {
      return true;
    }
  }

  // Check the columns
  for (int col = 0; col < 3; col++) {
    if (_board[0][col] == marker && _board[0][col] == _board[1][col] &&
        _board[1][col] == _board[2][col]) {
      return true;
    }
  }

  // Check top left diagonal
  if (_board[0][0] == marker && _board[0][0] == _board[1][1] &&
      _board[1][1] == _board[2][2]) {
    return true;
  }

  // Check top right diagonal
  if (_board[0][2] == marker && _board[0][2] == _board[1][1] &&
      _board[1][1] == _board[2][0]) {
    return true;
  }

  return false;
}
