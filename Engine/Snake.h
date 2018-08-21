#pragma once
#include "Location.h"
#include "Colors.h"
#include "Board.h"
#include "Frame.h"

class Snake
{

private:
	class Segment {
	public:
		void Follow(const Segment& next);
		void InitBody( int segments);
		void InitHead(const Location& in_loc);
		void MoveBy(const Location& delta_loc);
		void Draw( Board& brd);
		void Frame(Board& brd, Location& loc, int dimension);
		Location GetLocation() const;
	private:
		Location loc;
		Color c;
		Color f = Colors::Black;
		
		
	};

public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const ;
	Location GetHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& brd);
	bool SelfCollide(const Location & loc);
	bool SelfCollideWithEnd(const Location & rht);
private:
	static constexpr Color headColor = Colors::DarkGreen;
	Color bodyColor;
	static constexpr int nSegmentsmax = 100;
	Segment segments[nSegmentsmax];
	int nSegments = 1;


};