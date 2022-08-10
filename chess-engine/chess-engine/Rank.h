#pragma once

#include <array>
#define arr_i8 std::array<int, 8>

// 32 bit representation of a rank comprising 8 files. We are locked to a min size of 4 Bytes even with 
// unsigned char : 3 because the 3rd char cant overflow a byte (Hence char : 3 == char : 4) so might as 
// well make each piece of data a neat half byte. In adition using 4 bits means we can use signed and 
// remove the potential future issues of unsigned
struct Rank
{

private:
	short a : 4;
	short b : 4;
	short c : 4;
	short d : 4;
	short e : 4;
	short f : 4;
	short g : 4;
	short h : 4;

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