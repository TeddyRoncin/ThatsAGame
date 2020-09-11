#include "pch.h"

#include "game/Game.h"

Game::Game()
	:Renderer(), Input(), MapManager(), m_CurrentMap(getMap("map_test"))
{
	AddMap(m_CurrentMap);
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
