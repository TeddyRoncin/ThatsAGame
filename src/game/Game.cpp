#include "pch.h"

#include "game/Game.h"
#include "utils/Timer.h"
#include "entity/npc/SimpleNpc.h"

Game::Game()
	:Renderer(),
	Input(),
	MapManager(),
	m_CurrentMap(getMap("map_test")),
	m_Player("first player", 100, 100, 0.5, 0.5, "assets/img/test.png"), m_Entities()
{
	m_Entities.push_back(new SimpleNpc(0, 0));
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
	Timer timer(60);
	//Entity ent("font test", 10.0f, 10.0f);
	while(!isQuitting())
	{
		UpdateRender();
		RenderEntity(m_Player, m_CurrentMap.getWidth(), m_CurrentMap.getHeight());
		for (Npc* entity : m_CurrentMap.getEntities()) {
			entity->update();
			RenderEntity(*entity, m_CurrentMap.getWidth(), m_CurrentMap.getHeight());
		}
		/*for (Npc* entity : m_Entities) {
			entity->update();
			RenderEntity(*entity, m_CurrentMap.getWidth(), m_CurrentMap.getHeight());
			std::cout << "salut !" << std::endl;
		}*/
		//RenderEntity(ent, m_CurrentMap.getWidth(), m_CurrentMap.getHeight());
		Present();
		SDL_Event events;
		eventUpdate(events);
		timer.waitForNextFrame();
		//return;
	}
}
