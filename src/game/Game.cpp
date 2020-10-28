#include "pch.h"

#include "game/Game.h"
#include "utils/Timer.h"

Game::Game()
	:Renderer(), Input(),
	m_Player("first player", 400.0f, 400.0f, 200.0f, 200.0f, "assets/img/test.png")
{
	m_Entities.push_back(new SimpleNpc(map));
	AddMap(map);
}

Game::~Game()
{
	for (Npc* entity : m_Entities) {
		delete entity;
	}
}

void Game::loop()
{
	Timer timer(-1);
	while(!isQuitting())
	{
		UpdateRender();
		RenderEntity(m_Player);
		for (Npc* entity : m_Entities) {
			entity->update();
			RenderEntity(*entity);
		}
		Present();
		SDL_Event events;
		eventUpdate(events);
		timer.waitForNextFrame();
	}
}
