/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rd( std::random_device()() ),
	brd(gfx),
	frame(brd, GetGameDimension()),
	snake({2,2}),
	goal(rd, brd, snake, GetGameDimension()),
	block( brd, snake, goal)
	
{
}
//////
//std::random_device rd;
//std::mt19937 rng;
//std::uniform_int_distribution<int> pos;
//////

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!GameIsOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta_loc = { 0,-1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta_loc = { 0,1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta_loc = { -1,0 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta_loc = { 1,0 };
		}
	}
	

	++snakeMoveCounter;
	
	if (snakeMoveCounter >= snakeMovePeriod)
	{
		snakeMoveCounter = 0;
		Location next = snake.GetNextHeadLocation(delta_loc);

		if (!brd.IsInsideBoard( next, GetGameDimension()) || snake.SelfCollide(next) || block.Collide(next) )
		{
			GameIsOver = true;
		}
		else
		{
			bool IsEaten = next == goal.GetLocation();

			if (IsEaten)
			{
				snake.Grow();
			}
			
			snake.MoveBy(delta_loc);
			if (IsEaten)
			{
				goal.Respawn(rd, brd, snake, GetGameDimension());
				block.Respawn(brd, snake, goal);
				--snakeMovePeriod;
				++blockCount;
			}
			
		}
		
	}

	

}

void Game::ComposeFrame()
{

	snake.Draw(brd);
	goal.Draw(brd);

	block.Draw(brd, blockCount);

	
	frame.Draw(brd, GetGameDimension());
	if (GameIsOver)
	{
		SpriteCodex::DrawGameOver(400, 500, gfx);
	}
}
