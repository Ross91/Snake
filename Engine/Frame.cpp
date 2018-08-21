#include "Frame.h"

Frame::Frame(Board & brd, int dimension)
{
	
	Draw(brd, dimension);
}

void Frame::Draw(Board & brd, int dimension)
{
	const int width = dimension;
	const int height = dimension;

	brd.DrawFrame(0,0,width, height, c);
}


