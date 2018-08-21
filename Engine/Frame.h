#pragma once
#include "Board.h"
#include "Location.h"
#include "Colors.h"


class Frame
{
public:
	Frame(Board & brd, int dimension);
	void Draw(Board& brd, int dimension);

private:
	Color c = Colors::Green;
};