/*********************************************************************
 ** Author: Jordan Hamilton
 ** Date: 03/06/2018
 ** Description: Specification file for the Board class.
 *********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP


enum State { X_WON, O_WON, DRAW, UNFINISHED };

class Board {

  private:
    char gameBoard[3][3];

  public:
    Board();
    bool makeMove(int xCoordinate, int yCoordinate, char player);
    State gameState();
    void print();

};


#endif
