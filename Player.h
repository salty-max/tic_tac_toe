//
// Created by Maxime Blanc on 31/08/2021.
//

#pragma once
#include <string>

class Player {
public:
  explicit Player(int id);
  int getId() const;
  void setName();
  std::string getName();
  void setMarker();
  char getMarker() const;

private:
  int _id;
  std::string _name;
  char _marker{};
};