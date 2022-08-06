#pragma once

#include "Rank.h"

#pragma region Description
// The board is simply the positions of the pieces. It contains no history about the game 
// that has been played, number of moves without pawn move or capture etc. That will
// all be contained within the Game object which describes a single game permutation.
// 
// The tree branches expressing depth of N will consist of Boards, not Games. When a single
// move is chosen by the engine, that board and the Game prior to the move will construct
// a new Game. The reason for ordering the pices as i have is because it opens up opportunity
// in the future to easily sort arrays of pieces which may be beneficial when executing algorithms
// i.e. find all moves for all knights before all bishops to avoid running a knight function
// and then a bishop one (benefit of the i-cache)
//
// 0 = empty
// 1 = pawn
// 2 = knight
// 3 = bishop
// 4 = rook
// 5 = queen
// 6 = king
#pragma endregion

struct Board
{
	Rank ranks[8];

	// Default ctor should give default board
	Board()
	{

		arr_i8 white = { 4, 2, 3, 5, 6, 3, 2, 4 };
		arr_i8 black = { 4, 2, 3, 6, 5, 3, 2, 4 };
		arr_i8 pawn = { 1, 1, 1, 1, 1, 1, 1, 1 };
		arr_i8 empty = { 0, 0, 0, 0, 0, 0, 0, 0 };

		ranks[0] = Rank(white);
		ranks[1] = Rank(pawn);
		ranks[2] = Rank(empty);
		ranks[3] = Rank(empty);
		ranks[4] = Rank(empty);
		ranks[5] = Rank(empty);
		ranks[6] = Rank(pawn);
		ranks[7] = Rank(black);
	}

	// Copy ctor
	Board(const Board& b) 
	{
		for (int i = 0; i < sizeof(ranks)/sizeof(*ranks); i++)
			ranks[i] = b.ranks[i];
	}
};