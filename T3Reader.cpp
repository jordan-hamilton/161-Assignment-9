/*********************************************************************
 ** Author: Jordan Hamilton
 ** Date: 03/06/2018
 ** Description: This implements a class that replays a game of
 ** tic-tac-toe by reading data from a file. Data members are a
 ** tic-tac-toe board object from the Board class, and a character
 ** representing the current player. A method reads the game file
 ** to replay the game.
 *********************************************************************/

#include <fstream>

#include "T3Reader.hpp"

/*********************************************************************
** Description: Overloaded constructor to start a game by specifying
** the first player as a char (x or o).
*********************************************************************/
T3Reader::T3Reader(char firstPlayer) {

   gameBoard = Board();
   currentPlayer = firstPlayer;

   }

/*********************************************************************
** Description: This method takes a string represeting a file name,
** then uses integers in this file to call the makeMove method on the
** board object. The method returns true if all moves in the file were
** valid, or false if a move was invalid, if there were more moves
** in the file when the game ended, or if the file couldn't be read.
*********************************************************************/
bool T3Reader::readGameFile(std::string fileName) {

  // Define an ifstream so we can read a file of game moves
  std::ifstream inputFile;

  // Define integers to store data from the file that we can pass to
  // our board object's makeMove method.
  int coordinate1, coordinate2;

  inputFile.open(fileName);

  // Only attempt to read the file if it was opened successfully.
  if (inputFile) {

    // Store coordinates for the board in our variables if the
    // game hasn't ended yet.
    while (inputFile >> coordinate1 >> coordinate2 ) {

      if (gameBoard.gameState() == UNFINISHED) {

        // Make a move, but close the file and return false
        // if this wasn't a valid move.
        if (!gameBoard.makeMove(coordinate1, coordinate2, currentPlayer)) {
          inputFile.close();
          return false;
        }

       // Alternate the current player after a successful move.
       if (currentPlayer == 'x') {
         currentPlayer = 'o';
       } else {
         currentPlayer = 'x';
       }

     } else {
       // Close the file and return false if the game had ended with
       // moves remaining in our file.
       inputFile.close();
       return false;
     }

   }

 } else {
   // Ensure the file is closed and return false if we couldn't open the file.
   inputFile.close();
   return false;
 }


 // Close the file and return true after looping through the file
 // and replaying the game successfully.
 inputFile.close();
 return true;
}
