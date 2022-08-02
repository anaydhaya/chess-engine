#include "pch.h"

// Definitions to make the code more readable
#define EQ(val1, val2) EXPECT_EQ(val1, val2);

void TestRankByArray(const arr_i8& files, const arr_i8& vals)
{
	for (int i = 0; i < 8; i++)
		EQ(files[i], vals[i]);
}

#pragma region Rank Tests

TEST(RankTest, RankStructSize)
{
	Rank r;
	EQ(sizeof(r), 4)
}

TEST(RankTest, RankDefaultConstructor)
{
	Rank r;

	arr_i8 vals = { 0 };
	TestRankByArray(r.GetFileValsAsArray(), vals);
}

TEST(RankTest, RankCopyConstructor)
{
	Rank r;
	// auto vals = r.GetFileValsAsArray();
	arr_i8 new_vals = { 0, 1, 2, 3, 4, 5, 6, 7 };
	r.SetFileValsFromArray(new_vals);

	// Change values which we will test against
	/*for (int i = 0; i < 8; i++)
		vals[i] = new_vals[i];*/

	Rank c(r);
	TestRankByArray(c.GetFileValsAsArray(), new_vals);
}

TEST(RankTest, RankArrayConstructor)
{
	arr_i8 vals = { 0, 1, 2, 3, 4, 5, 6, 7 };
	Rank r(vals);
	TestRankByArray(r.GetFileValsAsArray(), vals);
}

TEST(RankTest, RankComparator)
{
	arr_i8 vals = { 0, 1, 2, 3, 4, 5, 6, 7 };
	Rank r(vals);
	Rank c(vals);
	EXPECT_TRUE(r == c);
}

#pragma endregion
#pragma region Board Tests

TEST(BoardTest, BoardDefault) 
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
		TestRankByArray(b.ranks[i].GetFileValsAsArray(), vals[i]);

	/*EQ(b.ranks[7].a, 4); EQ(b.ranks[7].b, 2); EQ(b.ranks[7].c, 3); EQ(b.ranks[7].d, 6); EQ(b.ranks[7].e, 5); EQ(b.ranks[7].f, 3); EQ(b.ranks[7].g, 2); EQ(b.ranks[7].h, 4);
	EQ(b.ranks[6].a, 1); EQ(b.ranks[6].b, 1); EQ(b.ranks[6].c, 1); EQ(b.ranks[6].d, 1); EQ(b.ranks[6].e, 1); EQ(b.ranks[6].f, 1); EQ(b.ranks[6].g, 1); EQ(b.ranks[6].h, 1);
	EQ(b.ranks[5].a, 0); EQ(b.ranks[5].b, 0); EQ(b.ranks[5].c, 0); EQ(b.ranks[5].d, 0); EQ(b.ranks[5].e, 0); EQ(b.ranks[5].f, 0); EQ(b.ranks[5].g, 0); EQ(b.ranks[5].h, 0);
	EQ(b.ranks[4].a, 0); EQ(b.ranks[4].b, 0); EQ(b.ranks[4].c, 0); EQ(b.ranks[4].d, 0); EQ(b.ranks[4].e, 0); EQ(b.ranks[4].f, 0); EQ(b.ranks[4].g, 0); EQ(b.ranks[4].h, 0);
	EQ(b.ranks[3].a, 0); EQ(b.ranks[3].b, 0); EQ(b.ranks[3].c, 0); EQ(b.ranks[3].d, 0); EQ(b.ranks[3].e, 0); EQ(b.ranks[3].f, 0); EQ(b.ranks[3].g, 0); EQ(b.ranks[3].h, 0);
	EQ(b.ranks[2].a, 0); EQ(b.ranks[2].b, 0); EQ(b.ranks[2].c, 0); EQ(b.ranks[2].d, 0); EQ(b.ranks[2].e, 0); EQ(b.ranks[2].f, 0); EQ(b.ranks[2].g, 0); EQ(b.ranks[2].h, 0);
	EQ(b.ranks[1].a, 1); EQ(b.ranks[1].b, 1); EQ(b.ranks[1].c, 1); EQ(b.ranks[1].d, 1); EQ(b.ranks[1].e, 1); EQ(b.ranks[1].f, 1); EQ(b.ranks[1].g, 1); EQ(b.ranks[1].h, 1);
	EQ(b.ranks[0].a, 4); EQ(b.ranks[0].b, 2); EQ(b.ranks[0].c, 3); EQ(b.ranks[0].d, 5); EQ(b.ranks[0].e, 6); EQ(b.ranks[0].f, 3); EQ(b.ranks[0].g, 2); EQ(b.ranks[0].h, 4);*/
}

TEST(BoardTest, BoardCopyConstructor) 
{

	// Does this even count as a test if it just uses the rank copy constructor? Is it a test in its own right?
	Board b;

	// arr_i8 empty = { 0 };
	arr_i8 vals[8] = { 0 };
	for (int i = 0; i < 8; i++)
		b.ranks[i].SetFileValsFromArray(vals[i]);

	Board copy(b);

	for (int i = 0; i < 8; i++)
		TestRankByArray(b.ranks[i].GetFileValsAsArray(), vals[i]);

	/*EQ(copy.ranks[0].a, 0); EQ(copy.ranks[0].b, 0); EQ(copy.ranks[0].c, 0); EQ(copy.ranks[0].d, 0); EQ(copy.ranks[0].e, 0); EQ(copy.ranks[0].f, 0); EQ(copy.ranks[0].g, 0); EQ(copy.ranks[0].h, 0);
	EQ(copy.ranks[1].a, 0); EQ(copy.ranks[1].b, 0); EQ(copy.ranks[1].c, 0); EQ(copy.ranks[1].d, 0); EQ(copy.ranks[1].e, 0); EQ(copy.ranks[1].f, 0); EQ(copy.ranks[1].g, 0); EQ(copy.ranks[1].h, 0);
	EQ(copy.ranks[2].a, 0); EQ(copy.ranks[2].b, 0); EQ(copy.ranks[2].c, 0); EQ(copy.ranks[2].d, 0); EQ(copy.ranks[2].e, 0); EQ(copy.ranks[2].f, 0); EQ(copy.ranks[2].g, 0); EQ(copy.ranks[2].h, 0);
	EQ(copy.ranks[3].a, 0); EQ(copy.ranks[3].b, 0); EQ(copy.ranks[3].c, 0); EQ(copy.ranks[3].d, 0); EQ(copy.ranks[3].e, 0); EQ(copy.ranks[3].f, 0); EQ(copy.ranks[3].g, 0); EQ(copy.ranks[3].h, 0);
	EQ(copy.ranks[4].a, 0); EQ(copy.ranks[4].b, 0); EQ(copy.ranks[4].c, 0); EQ(copy.ranks[4].d, 0); EQ(copy.ranks[4].e, 0); EQ(copy.ranks[4].f, 0); EQ(copy.ranks[4].g, 0); EQ(copy.ranks[4].h, 0);
	EQ(copy.ranks[5].a, 0); EQ(copy.ranks[5].b, 0); EQ(copy.ranks[5].c, 0); EQ(copy.ranks[5].d, 0); EQ(copy.ranks[5].e, 0); EQ(copy.ranks[5].f, 0); EQ(copy.ranks[5].g, 0); EQ(copy.ranks[5].h, 0);
	EQ(copy.ranks[6].a, 0); EQ(copy.ranks[6].b, 0); EQ(copy.ranks[6].c, 0); EQ(copy.ranks[6].d, 0); EQ(copy.ranks[6].e, 0); EQ(copy.ranks[6].f, 0); EQ(copy.ranks[6].g, 0); EQ(copy.ranks[6].h, 0);
	EQ(copy.ranks[7].a, 0); EQ(copy.ranks[7].b, 0); EQ(copy.ranks[7].c, 0); EQ(copy.ranks[7].d, 0); EQ(copy.ranks[7].e, 0); EQ(copy.ranks[7].f, 0); EQ(copy.ranks[7].g, 0); EQ(copy.ranks[7].h, 0);*/
}

#pragma endregion