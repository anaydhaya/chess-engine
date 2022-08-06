#pragma once

#include <array>
#define arr_b8 std::array<bool, 8>

struct EnPassant
{

private:
	bool one : 1;
	bool two : 1;
	bool three : 1;
	bool four : 1;
	bool five : 1;
	bool six : 1;
	bool seven : 1;
	bool eight : 1;

public:
	EnPassant()
	{
		SetFilesFromArray({ 0 });
	}

	EnPassant(const arr_b8& vals)
	{
		SetFilesFromArray(vals);
	}

	EnPassant(const EnPassant& e)
	{
		SetFilesFromArray(e.GetFilesAsArray());
	}

	bool operator==(const EnPassant& rhs) const
	{
		return memcmp(this, &rhs, sizeof(EnPassant)) == 0;
	}

	void SetFilesFromArray(const arr_b8& vals)
	{
		one = vals[0];
		two = vals[1];
		three = vals[2];
		four = vals[3];
		five = vals[4];
		six = vals[5];
		seven = vals[6];
		eight = vals[7];
	}

	arr_b8 GetFilesAsArray() const
	{
		return { one, two, three, four, five, six, seven, eight };
	}
};