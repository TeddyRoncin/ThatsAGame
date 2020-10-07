#include "pch.h"

#include "game/Game.h"
#include "utils/Timer.h"

Game::Game()
	:Renderer(), Input(), MapManager(), m_CurrentMap(getMap("map_test")),
	m_Player("first player", 100, 100, 0.5, 0.5, "assets/img/test.png"), m_Entities()
{
	m_Entities.push_back(new SimpleNpc(m_CurrentMap));
	AddMap(m_CurrentMap);
	// auto[playerx, playery] = m_Player.m_pos.getPosition();
	// auto[playerw, playerh] = m_Player.m_dim.getDimension();
	//AddTexture(m_Player.m_sprite, playerx, playery, playerw, playerh, Layer::Top);
	//AddTexture(m_Entities[0]->m_sprite, m_Entities[0]->m_pos.getX() * 100, m_Entities[0]->m_pos.getY()*100,
	//			m_Entities[0]->m_dim.getWidth(), m_Entities[0]->m_dim.getHeight(), Layer::Top);
	//Clear();
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
		RenderEntity(m_Player);
		for (Npc* entity : m_Entities) {
			entity->update();
			RenderEntity(*entity);
		}
		Render();
		SDL_Event events;
		eventUpdate(events);
		//std::cout << "FPS : " << timer.getFps() << std::endl;
		timer.waitForNextFrame();
		Clear();
	}
}
