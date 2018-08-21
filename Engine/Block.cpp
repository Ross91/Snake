#include "Block.h"


void Block::piece::Respawn(Board & brd, Snake & snake, Goal & goal)
{
	
	std::uniform_int_distribution<int> xpos(0, 19);
	std::uniform_int_distribution<int> ypos(0, 19);



	Location newLoc;
	do
	{
		newLoc.x = xpos(rng);
		newLoc.y = ypos(rng);

	} while (snake.SelfCollide(newLoc) && goal.Collide(newLoc));

	loc = newLoc;
}

void Block::piece::Draw(Board & brd)
{
	assert(loc.x < 0);
	assert(loc.x >= 500);
	assert(loc.y < 0);
	assert(loc.y >= 500);

	brd.DrawCell(loc, c);
}


Location Block::piece::GetLocation()
{
	return loc;
}

void Block::Draw(Board& brd)
{
	for (int i = blocksNum; i > 0; --i)
	{
		piece[i].Draw(brd);
	}
}

bool Block::Collide(Location & in_loc)
{
	for (int i = blocksNum; i > 0; --i)
	{
		if (piece[i].GetLocation() == in_loc)
		{
			return true;
		}
	}
	return false;
}
