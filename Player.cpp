//
// Created by Maxime Blanc on 31/08/2021.
//

#include "Player.h"
#include <iostream>

Player::Player(int id) { _id = id; }

int Player::getId() const { return _id; }

void Player::setName() {
  std::cout << "Enter player " << _id << " name: ";
  std::cin >> _name;
}

std::string Player::getName() { return _name; }

void Player::setMarker() {
  std::string input;
  bool isBadInput = true;

  while (isBadInput) {
    std::cout << "Enter " << _name << "'s marker: ";
    std::cin >> input;

    if (input.length() > 1) {
      std::cout << "Marker must be a single character!" << std::endl;
    } else {
      isBadInput = false;
    }
  }

  _marker = input[0];
}

char Player::getMarker() const { return _marker; }
