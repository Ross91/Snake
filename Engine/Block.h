#pragma once
#include "Location.h"
#include "Snake.h"
#include "Board.h"
#include "Colors.h"
#include "Goal.h"
#include <random>
#include <assert.h>

class Block
{
public:
	Block(Board& brd, Snake& snake, Goal& goal) 
	{
		for (int i = blocksNum; i > 0; --i)
		{
			piece[i].Respawn(brd, snake, goal);
		}
	}

	void Draw(Board& brd);
	bool Collide(Location& in_loc);
private:

	class piece
	{
	public:
		void Respawn(Board& brd, Snake& snake, Goal& goal);
		void Draw(Board& brd);
		Location GetLocation();
	private:
		Location loc;
		Color c = Colors::Magenta;
		std::mt19937 rng;

	};
	
	static constexpr int blocksNum = 5;
	piece piece[blocksNum];

};
