#pragma once
#include "Location.h"
#include "Board.h"
#include "Colors.h"
#include "Snake.h"
#include <random>
#include "Graphics.h" 
class Goal
{
public:
	Goal(std::mt19937& rng, Board& brd, Snake& snake, int dimension);
	void Respawn(std::mt19937& rng, Board& brd, Snake& snake, int dimension);
	void Draw(Board& brd);
	const Location& GetLocation();
	bool Collide(Location& rhs);
private:

	Location loc;
	Color main = Colors::White;
};