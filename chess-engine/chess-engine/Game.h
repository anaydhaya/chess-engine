#pragma once

#include "Board.h"

#pragma region Description
// The Game object holds the current board as well as other meta data such as moves 
// since last pawn move or capture, repeat counter and so on - basically the Game is
// concerned about all the rules of Chess wehereas the board is simply the piece positions
#pragma endregion

class Game
{

	// When a move is made, we construct a new Game from the old Game and the new Board
	Game(const Game& game, const Board& board)
	{

	private:
		int movesWithoutCaptureOrPawnMove = 0;
		int repeatCount = 0;

	}
};