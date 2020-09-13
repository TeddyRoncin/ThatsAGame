#include "pch.h"

#include "game/Game.h"

Game::Game()
	:Renderer(), Input(), MapManager(), m_CurrentMap(getMap("map_test")), m_Player("first player", 100,100,50,50,"assets/img/test.png")
{
	AddMap(m_CurrentMap);
	auto[playerx, playery] = m_Player.m_pos.getPosition();
	auto[playerw, playerh] = m_Player.m_dim.getDimension();
	AddTexture(m_Player.m_sprite, playerx, playery, playerw, playerh, Layer::Top);
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
		RenderPlayer(m_Player);
		SDL_Event events;
		eventUpdate(events);
	}
}
