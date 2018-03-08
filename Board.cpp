/*********************************************************************
 ** Author: Jordan Hamilton
 ** Date: 03/06/2018
 ** Description: This implements a class that represents a tic-tac-toe
 ** board.
 *********************************************************************/

#include <iostream>

#include "Board.hpp"


/*********************************************************************
** Description: Default constructor to initialize the board array with
** all spaces by assigning the ASCII code for a space character (32).
*********************************************************************/
Board::Board() {

  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      gameBoard[x][y] = 32;
    }
  }

}

/*********************************************************************
** Description: Set the provided location on the board equal to the
** char passed to the function and return true, only if we detect a
** space in that array element by checking for ASCII code 32.
*********************************************************************/
bool Board::makeMove(int xCoordinate, int yCoordinate, char player) {

  if (gameBoard[xCoordinate][yCoordinate] == 32) {
    gameBoard[xCoordinate][yCoordinate] = player;
    return true;
  } else {
    return false;
  }

}


/*********************************************************************
** Description: Find and return the game's current state by checking
** for a  multiple of the ASCII code for 'x' or 'o' in a row, column
** or diagonal. Return a draw if the board is full without a winner,
** or unfinished if there isn't a winner and the board isn't full.
*********************************************************************/
State Board::gameState() {

    // Initialize the game's current state to UNFINISHED before we make
    // any determination.
    State gameState = UNFINISHED;

    // Define and initialize an accumulator for each row, column
    // or diagonal to determine if there's a winning player.
    int rowSum, columnSum, diagonalSum1, diagonalSum2;

    // Define and initialize an accumulator for all elements in the array.
    int total = 0;

    // Check for a winning player in each column.
    for (int x = 0; x < 3; x++) {

      // Set our sums to 0 before starting the inner loop to check a row
      // or column.
      rowSum = 0;
      columnSum = 0;

      for (int y = 0; y < 3; y++) {
        columnSum += gameBoard[x][y];
        rowSum += gameBoard[y][x];
        total += gameBoard[x][y];
      }

      // See if the sum of a single row or column is a multiple of the
      // ASCII code for a single character, indicating that that player
      // won.
      if (rowSum == 111 * 3 || columnSum == 111 * 3) {
        gameState = O_WON;
        return gameState;
      } else if (rowSum == 120 * 3 || columnSum == 120 * 3) {
        gameState = X_WON;
        return gameState;
      }

    }

    // If the center of the board is not a space, check diagonals for a
    // winning player.
    if (gameBoard[1][1] != 32) {

      // Sum the ASCII codes of both possible diagonals within the array.
      diagonalSum1 = gameBoard[0][0]+ gameBoard[1][1] + gameBoard[2][2];
      diagonalSum2 = gameBoard[0][2]+ gameBoard[1][1] + gameBoard[2][0];

      if (diagonalSum1 == 111 * 3 || diagonalSum2 == 111 * 3) {
        gameState = O_WON;
        return gameState;
      } else if (diagonalSum1 == 120 * 3 || diagonalSum2 == 120 * 3) {
        gameState = X_WON;
        return gameState;
      }

    }

    // Declare a draw if the board is filled with valid characters
    // (9 array elements with an ASCII code of at least 111) but we couldn't
    // find a winner.
    if (total >= 111 * 9) {
      gameState = DRAW;
    }

    // Return either a draw if we were able to determine one,
    // or the game is unfinished.
    return gameState;

  }


  /*********************************************************************
  ** Description: Create a visually stunning tic-tac-toe board.
  *********************************************************************/
  void Board::print() {

    std::cout << " ___________ " << std::endl;
    for (int y = 0; y < 3; y++) {
      for (int x = 0; x < 3; x++) {
        std::cout << "|_" << gameBoard[x][y] << "_";
      }
      std::cout << "|" << std::endl;
    }

  }
