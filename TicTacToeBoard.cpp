#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Switches turn member variable to represent whether it's X's or O's turn
void TicTacToeBoard::toggleTurn()
{
 if(turn==X){turn=O;}
 else{turn=X;}
}

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
	turn=X;
	for(int row=0;row<3;row++){
	 for(int column=0;column<3;column++){
	  board[column][row]=Blank;
	 }
	}
}

//Resets each board location to the Blank Piece value
void TicTacToeBoard::clearBoard()
{
 for(int h=0;h<3;h++)
 {
  for(int w=0;w<3;w++)
  {
   board[w][h]=Blank;
  }
 }
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
 if(row<3 || column<3 || board[column][row]==Blank){
  board[row][column]=turn;
  Piece currentTurn=turn;
  toggleTurn();
  return currentTurn;
 }
 else{
  return Invalid;
 }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
 if(row<3 || column <3){
   return turn;
 }
 else{
  return Invalid;
 }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  int row, column;
  int c=0;
  int c1=0;
  int c2=0;
  for(column=0;column<3;column++){
   for(row=0;row<3;row++){
    if(board[row][column]==turn)
	c++;
    if(board[column][row]==turn)
	c1++;
    if(row==column && board[column][row]==turn)
	c2++;
     }
   if(c==3 || c1==3 || c2==3)
     return turn;
   else{
     c=0;
     c1=0;
   }
  }
  if(board[0][2]==turn && board[1][1] ==turn && board[2][0] ==turn)
	return turn;
  else
   return Invalid;
}
