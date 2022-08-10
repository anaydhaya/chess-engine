#pragma once

#include "Board.h"
#include "EnPassant.h"

#pragma region Description
// The Game object holds the current board as well as other meta data such as moves 
// since last pawn move or capture, repeat counter and so on - basically the Game is
// concerned about all the rules of Chess wehereas the board is simply the piece positions

// Becuase this object will be interacted with much less than the board for example
// (with the exception of some getters like can en-passant or can castle which will
// determine potential moves)

// When this engine runs as a dll, it will need some external facing interface that the
// actual chess game hooks into. For that reason, this Game should just serve as a
// remote proxy for the Game object that calls it - will need a function that can
// construct a game from scratch then

// Would need functions to take a generic FEN and PGN and produce a Game and Board
#pragma endregion

class Game
{
	Game() {}

	// When a move is made, we construct a new Game from the old Game and the new Board
	Game(const Game& game, const Board& board)
	{

		// This will need to find the move and then process the consequences
		// Get diff between game.Board and board - this is the move (which can be a castle) - 
		// This would be better as a function on two boards becuase otherwise we need to store 
		// a move with each board. As a function we just need a board and the parent board in the tree
		// This function will handle the changing of private data based on the new board and the previous game

	}

	// PGN Constructor?

	// FEN Constructor?

	// Copy Constructor

	int MovesWithoutCaptureOrPawnMove() { return movesWithoutCaptureOrPawnMove; }
	int RepeatCount() { return repeatCount; }
	bool WhiteCanShortCastle() { return whiteCanShortCastle; }
	bool WhiteCanLongCastle() { return whiteCanLongCastle; }
	bool BlackCanShortCastle() { return blackCanShortCastle; }
	bool BlackCanLongCastle() { return blackCanLongCastle; }

private:

	Board board;

	int movesWithoutCaptureOrPawnMove = 0;
	int repeatCount = 0;
	int moveCounter = 0;

	// By default both players can castle both ways
	bool whiteCanShortCastle = true;
	bool whiteCanLongCastle = true;
	bool blackCanShortCastle = true;
	bool blackCanLongCastle = true;

	// two arrays of 8. These are updated after every move to indicate if any pawns can en passant
	EnPassant whiteCanEnPassant;
	EnPassant blackCanEnPassant;
};