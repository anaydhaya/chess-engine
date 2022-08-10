#include "pch.h"

#pragma region Thoughts
// Unit tests for the Game representation. Should be in dependency order.
// Im not that familiar with writing unit tests but it seems like making
// things that inherently rely on others purely unit is basically impossible.
// For example, you cant possible test a Game object without testing Board.
// And if any error happens lower down in the dependency you expect to see errors
// propagate? Not sure what the general process is then but ill try and 
// get something that makes sense to me and brings value
#pragma endregion

// Definitions to make the code more readable
#define EQ(val1, val2) EXPECT_EQ(val1, val2);

void TestRankByArray(const arr_i8& files, const arr_i8& vals)
{
	for (int i = 0; i < 8; i++)
		EQ(files[i], vals[i]);
}

void TestRankByArray(const arr_b8 files, const arr_b8 vals)
{
	for (int i = 0; i < 8; i++)
		EQ(files[i], vals[i]);
}

#pragma region Rank Tests

TEST(RankTest, StructSize)
{
	Rank r;
	EQ(sizeof(r), 4)
}

TEST(RankTest, DefaultConstructor)
{
	Rank r;

	arr_i8 vals = { 0 };
	TestRankByArray(r.GetFilesAsArray(), vals);
}

TEST(RankTest, CopyConstructor)
{
	Rank r;
	arr_i8 new_vals = { 0, 1, 2, 3, 4, 5, 6, 7 };
	r.SetFilesFromArray(new_vals);

	Rank c(r);
	TestRankByArray(c.GetFilesAsArray(), new_vals);
}

TEST(RankTest, ArrayConstructor)
{
	arr_i8 vals = { 0, 1, 2, 3, 4, 5, 6, 7 };
	Rank r(vals);
	TestRankByArray(r.GetFilesAsArray(), vals);
}

TEST(RankTest, Comparator)
{
	arr_i8 vals = { 0, 1, 2, 3, 4, 5, 6, 7 };
	Rank r(vals);
	Rank c(vals);
	EXPECT_TRUE(r == c);
}

#pragma endregion

#pragma region Board Tests

TEST(BoardTest, DefaultConstructor) 
{

	// [4 2 3 6 5 3 2 4] Black
	// [1 1 1 1 1 1 1 1]
	// [0 0 0 0 0 0 0 0]
	// [0 0 0 0 0 0 0 0]
	// [0 0 0 0 0 0 0 0]
	// [0 0 0 0 0 0 0 0]
	// [1 1 1 1 1 1 1 1]
	// [4 2 3 5 6 3 2 4] White

	arr_i8 vals[8] = {
		{4, 2, 3, 5, 6, 3, 2, 4},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{4, 2, 3, 6, 5, 3, 2, 4}
	};

	Board b;

	for (int i = 0; i < 8; i++)
		TestRankByArray(b.ranks[i].GetFilesAsArray(), vals[i]);
}

TEST(BoardTest, CopyConstructor) 
{

	// Does this even count as a test if it just uses the rank copy constructor? Is it a test in its own right?
	Board b;

	// arr_i8 empty = { 0 };
	arr_i8 vals[8] = { 0 };
	for (int i = 0; i < 8; i++)
		b.ranks[i].SetFilesFromArray(vals[i]);

	Board copy(b);

	for (int i = 0; i < 8; i++)
		TestRankByArray(b.ranks[i].GetFilesAsArray(), vals[i]);
}

#pragma endregion

#pragma region EnPassant Tests

TEST(EnPassantTest, StructSize)
{
	EnPassant e;
	EQ(sizeof(e), 1);
}

TEST(EnPassantTest, DefaultConstructor)
{
	EnPassant e;

	arr_b8 vals = { 0 };
	TestRankByArray(e.GetFilesAsArray(), vals);
}

TEST(EnPassantTest, CopyConstructor)
{
	EnPassant e;
	arr_b8 new_vals = { 0, 1, 0, 1, 0, 1, 0, 1 };
	e.SetFilesFromArray(new_vals);

	EnPassant c(e);
	TestRankByArray(c.GetFilesAsArray(), new_vals);
}

TEST(EnPassantTest, ArrayConstructor)
{
	arr_b8 vals = { 0, 1, 2, 3, 4, 5, 6, 7 };
	EnPassant e(vals);
	TestRankByArray(e.GetFilesAsArray(), vals);
}

TEST(EnPassantTest, Comparator)
{
	arr_b8 vals = { 0, 1, 2, 3, 4, 5, 6, 7 };
	EnPassant e(vals);
	EnPassant c(vals);
	EXPECT_TRUE(e == c);
}

#pragma endregion

#pragma region Game Tests

TEST(GameTests, DefaultConstructor)
{

}

TEST(GameTests, PermutationConstructor)
{

}

#pragma endregion