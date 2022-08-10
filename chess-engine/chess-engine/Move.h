#pragma once

#include <array>

#pragma region Description
// Class hierarchy of moves. It's okay to use OOP here
// as with the less efficient areas of Game because i dont expect
// it to be a bottleneck of the system

// There has to be a function to convert 'moves' into text notation
// and a way to apply text notation moves to a board (if the move is valid)
#pragma endregion

//// Non-Virtual-Interface idiom
//class IMove
//{
//public:
//	
//	virtual ~IMove() = default;
//private:
//	
//	bool capture = false;
//};