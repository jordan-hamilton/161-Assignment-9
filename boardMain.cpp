#include <iostream>
#include "Board.hpp"

int main() {
  Board board1;
  board1.makeMove(0,0,'x');
  board1.makeMove(0,1,'o');
  board1.makeMove(0,2,'x');
  board1.makeMove(1,0,'x');
  board1.makeMove(1,1,'x');
  board1.makeMove(1,2,'x');
  board1.print();
  return 0;
}
