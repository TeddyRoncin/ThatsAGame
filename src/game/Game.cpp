#include "pch.h"

#include "game/Game.h"

Game::Game()
	:Renderer(), Input(), MapManager(), m_CurrentMap(getMap("Super Map ^^"))
{
	AddMap(m_CurrentMap); // change this must be polymorphique !!!
	Clear();
}

Game::~Game()
{
}

void Game::loop()
{
	while(!isQuitting())
	{
		Render();
		SDL_Event events;
		eventUpdate(events);
	}
}
