#include "Snake.h"
#include "Colors.h"
#include <assert.h>

Snake::Snake(const Location& loc)

{
	segments[0].InitHead(loc);
	
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location & delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

Location Snake::GetHeadLocation(const Location & delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::Grow()
{
	if (nSegments < nSegmentsmax)
	{
		segments[nSegments].InitBody(nSegments);
		++nSegments;
	}
}



void Snake::Draw(Board & brd)
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].Draw(brd);
	}
}

bool Snake::SelfCollide(const Location & rht)
{
	for (int i = 0; i < nSegments - 1; ++i)
	{
		if (segments[i].GetLocation() == rht)
		{
			return true;
		}
	}

	return false;
}
bool Snake::SelfCollideWithEnd(const Location & rht)
{
	for (int i = 0; i < nSegments; ++i)
	{
		if (segments[i].GetLocation() == rht)
		{
			return true;
		}
	}

	return false;
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}



void Snake::Segment::MoveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board & brd)
{

	brd.DrawCell(loc, c);
	brd.DrawFrame(loc.x * 20, loc.y * 20, loc.x * 20 + 20, loc.y * 20 + 20, f);
}

void Snake::Segment::Frame(Board & brd, Location & loc, int dimension )
{
	//int DimSub = dimension - 1 ;
	// loc.x * dimension, loc.y * dimension, dimension, dimension
	//brd.DrawFrame( c);
}

Location Snake::Segment::GetLocation() const
{
	return loc;
}

void Snake::Segment::InitBody(int segments)
{

	if (segments % 2 == 0)
	{
		c = Colors::MedGreen;
	}
	else if (segments % 3 == 0)
	{
		c = Colors::LightGreen;
	}

	else
	{
		c = Colors::LightestGreen;
	}

}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}
