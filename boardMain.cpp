#include <iostream>
#include "Board.hpp"

int main() {

  Board board1;

  board1.makeMove(0,0,'o');
  board1.makeMove(0,1,'x');
  board1.makeMove(0,2,'x');
  board1.makeMove(1,0,'o');
  board1.makeMove(1,1,'x');
  board1.makeMove(1,2,'x');
  board1.makeMove(2,0,'x');
  board1.makeMove(2,1,'x');
  board1.makeMove(2,2,'o');

  board1.print();

  std::cout << "Current game state: " << std::endl;

  switch(board1.gameState()) {
    case 0: std::cout << "X won!" << std::endl;
            break;
    case 1: std::cout << "O won!" << std::endl;
            break;
    case 2: std::cout << "It's a draw!" << std::endl;
            break;
    case 3: std::cout << "It's not over!" << std::endl;
            break;
  }
  
  return 0;
}
