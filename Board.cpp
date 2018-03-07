/*********************************************************************
 ** Author: Jordan Hamilton
 ** Date: 03/06/2018
 ** Description: This implements a class that represents a tic-tac-toe
 ** board.
 *********************************************************************/

#include <iostream>

#include "Board.hpp"

Board::Board() {
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      gameBoard[x][y] = 32;
    }
  }
}

bool Board::makeMove(int xCoordinate, int yCoordinate, char player) {
  if (gameBoard[xCoordinate][yCoordinate] == 32) {
    gameBoard[xCoordinate][yCoordinate] = player;
    return true;
  } else {
    return false;
  }
}

State Board::gameState() {
    State gameState = UNFINISHED;
  }

void Board::print() {
  std::cout << " ___________ " << std::endl;
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      std::cout << "|_" << gameBoard[x][y] << "_";
    }
    std::cout << "|" << std::endl;
  }
}
