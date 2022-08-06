#pragma once

#include <array>
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
		SetFilesFromArray({ 0 });
	}

	Rank(arr_i8 r)
	{
		SetFilesFromArray(r);
	}

	Rank(const Rank& r)
	{
		SetFilesFromArray(r.GetFilesAsArray());
	}

	bool operator==(const Rank& rhs) const
	{
		return memcmp(this, &rhs, sizeof(Rank)) == 0;
	}

	arr_i8 GetFilesAsArray() const
	{
		return { a, b, c, d, e, f, g, h };
	}

	void SetFilesFromArray(const arr_i8& arr)
	{
		a = arr[0];
		b = arr[1];
		c = arr[2];
		d = arr[3];
		e = arr[4];
		f = arr[5];
		g = arr[6];
		h = arr[7];
	}
};