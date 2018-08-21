#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}
void Board::DrawCell(Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < Graphics::ScreenWidth);
	assert(loc.y >= 0);
	assert(loc.y < Graphics::ScreenHeight);

	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}



void Board::DrawFrame(int x0, int y0, int x1, int y1, Color c)
{
	gfx.DrawFrame(x0, y0, x1, y1, c);
}



int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

int Board::IsInsideBoard(const Location & loc, int dimension) const
{
	return loc.x >= 0 && loc.x < 20  &&
		loc.y >= 0 && loc.y < 20 ;
}

