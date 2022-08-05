#pragma once

#include <array>

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

#define arr_i8 std::array<int, 8>

// 32 bit representation of a rank comprising 8 files. We are locked to a min size of 4 Bytes whether we use 
// unsigned char : 3 or unsigned short : 4 so might as well make each piece of data a neat half byte
struct Rank
{

private:
	unsigned short a : 4;
	unsigned short b : 4;
	unsigned short c : 4;
	unsigned short d : 4;
	unsigned short e : 4;
	unsigned short f : 4;
	unsigned short g : 4;
	unsigned short h : 4;

public:

	Rank()
	{
		arr_i8 vals = { 0 };
		SetFileValsFromArray(vals);
	}

	Rank(arr_i8 r)
	{
		SetFileValsFromArray(r);
	}

	Rank(const Rank& r)
	{
		arr_i8 vals = r.GetFileValsAsArray();
		SetFileValsFromArray(vals);
	}

	bool operator==(const Rank& rhs) const
	{
		return memcmp(this, &rhs, sizeof(Rank)) == 0;
	}

	arr_i8 GetFileValsAsArray() const
	{
		return { a, b, c, d, e, f, g, h };
	}

	void SetFileValsFromArray(const arr_i8& vals)
	{
		a = vals[0];
		b = vals[1];
		c = vals[2];
		d = vals[3];
		e = vals[4];
		f = vals[5];
		g = vals[6];
		h = vals[7];
	}
};

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