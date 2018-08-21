#include "Goal.h"
#include "Graphics.h"

Goal::Goal(std::mt19937& rng, Board& brd, Snake& snake, int dimension)
{
	Respawn(rng, brd, snake, dimension);
}



void Goal::Respawn(std::mt19937& rng, Board& brd, Snake& snake, int dimension)
{
	std::uniform_int_distribution<int> xpos(0, 19 );
	std::uniform_int_distribution<int> ypos(0, 19 );

	Location newLoc;
	do
	{
		newLoc.x = xpos(rng);
		newLoc.y = ypos(rng);

	} while (snake.SelfCollideWithEnd(newLoc));

	loc = newLoc;

}

void Goal::Draw(Board & brd)
{
	brd.DrawCell(loc, main);
}

const Location & Goal::GetLocation()
{
	return loc;
}

bool Goal::Collide(Location & rhs)
{
	if (loc == rhs)
	{
		return true;
	}

	return false;
}

