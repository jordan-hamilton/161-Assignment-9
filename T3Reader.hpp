/*********************************************************************
 ** Author: Jordan Hamilton
 ** Date: 03/06/2018
 ** Description: Specification file for the T3Reader class.
 *********************************************************************/

#ifndef T3READER_HPP
#define T3READER_HPP

#include <string>

#include "Board.hpp"


class T3Reader {

  private:
    Board gameBoard;
    char currentPlayer;

  public:
    T3Reader(char firstPlayer);
    bool readGameFile(std::string gameFile);

};


#endif
