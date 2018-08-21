#pragma once
#include "Graphics.h"
#include "Location.h"
#include <assert.h>

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell( Location& loc, Color c);
	void DrawFrame(int x0, int y0, int x1, int y1, Color c);
	int GetGridWidth() const;
	int GetGridHeight() const;
	int IsInsideBoard(const Location& loc, int dimension) const;

private:
	static constexpr int dimension = 20;
	static constexpr int width = 20;
	static constexpr int height = 20;
	Graphics& gfx;
};