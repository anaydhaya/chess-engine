#pragma once

#include <array>

#pragma region Description
// Class hierarchy of moves. It's okay to use OOP here
// as with the less efficient areas of Game because i dont expect
// it to be a bottleneck of the system
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