//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include "Game.h"

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}