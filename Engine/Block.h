#pragma once
#include "Location.h"
#include "Snake.h"
#include "Board.h"
#include "Colors.h"
#include "Goal.h"
#include <random>

class Block
{
public:
	Block( Board& brd, Snake& snake, Goal& goal)
	{
		Respawn( brd, snake, goal);
	}
	void Respawn( Board& brd, Snake& snake, Goal& goal);
	void Draw(Board& brd, int num);
	bool Collide(Location& in_loc);
private:
	Location loc;
	Color c = Colors::Gray;
	std::mt19937 rng;

};
