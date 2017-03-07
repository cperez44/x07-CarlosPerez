/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
TEST(TicTacToeBoardTest, BoardIsClear)
{
	TicTacToeBoard TT;
	for(int row=0;row<3;row++){
		for(int column=0;column<3;column++){
			EXPECT_EQ(' ', TT.getPiece(row,column));
		}
	}
}
TEST(TicTacToeBoardTest, FirstMoveCheck)
{
	TicTacToeBoard TT;
	Piece check=TT.placePiece(0,0);
	EXPECT_EQ('X',check);
}
TEST(TicTacToeBoardTest, BoardGetsCleared)
{
	TicTacToeBoard TT;
	for(int row=0;row<3;row++){
		for(int column=0;column<3;column++){
			TT.placePiece(row,column);
		}
	}
	TT.clearBoard();
	for(int row;row<3;row++){
		for(int column=0;column<3;column++){
			EXPECT_EQ(' ', TT.getPiece(row,column));
		}
	}
}
