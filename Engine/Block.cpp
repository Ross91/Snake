#include "Block.h"

void Block::Respawn( Board & brd, Snake& snake, Goal& goal )
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

void Block::Draw(Board & brd, int num)
{
	for (int i = num; i <= 0; --i)
	{
		brd.DrawCell(loc, c);
	}
	
}

bool Block::Collide(Location& in_loc)
{
	if (loc == in_loc)
	{
		return true;
	}
	else
	{
		return false;
	}
}
