#pragma once

#pragma region The plan
// The focus of this engine initially should be really efficient board storage. I want to test the performance 
// of a small 2d or flattened 1d array of uint8s and see how the performance is relative to a bitboard. The 
// objective being that enabling a higher depth might yield a better engine. If it seems like the engine depth 
// gives significantly diminishing returns then the focus will likely switch to a better pruning and move 
// selection algorithm. The engine will brute force N depth of moves in a tree where boards that already exist 
// within the tree are ignored (need to find a good way to do this, memcmp is fast but its a matter of skipping 
// repeat boards at the time or having a stage after where all tree branches are checked for repeats. It should 
// be that after the first move that calculates a depth N tree, for each move that is made, we are left with 
// a tree of depth N-1 and should only have to calculate the Nth depth
//
// To begin with i don't think i'll include an openings database or endgame tablebase
#pragma endredion

class Engine
{
	
};