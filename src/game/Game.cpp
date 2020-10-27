#include "pch.h"

#include "game/Game.h"
#include "utils/Timer.h"
#include "entity/npc/SimpleNpc.h"
#include "entity/npc/ai/PathFinder.h"
#include "bmploader/BMPFile.h"
#include "bmploader/BMPImage.h"
#include "map/EmptyMapElement.h"
#include "map/WallMapElement.h"

namespace pt = boost::property_tree;
namespace fs = std::filesystem;

Game::Game()
	:Renderer(), Input(), MapManager(), m_CurrentMap(getMap("map_test")),
	m_Player("first player", 0.0f, 2.0f, 1.0f, 1.0f, "assets/textures/test2.png")
{
	//m_Entities.push_back(new SimpleNpc(0, 0));
	//((SimpleNpc*) m_Entities[0])->addPathFinder(PathFinder(m_CurrentMap));
	AddMap(m_CurrentMap);
	PathFinder pathFinder(m_CurrentMap);
    for (Npc* entity : getEntitiesOf(m_CurrentMap)) {
        entity->addPathFinder(pathFinder);
    }
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
		//std::cout << "le nb dentités de la map : " << m_CurrentMap.getEntities().size() << std::endl;
		UpdateRender();
		RenderEntity(m_Player, m_CurrentMap.getWidth(), m_CurrentMap.getHeight());
		for (Npc* entity : getEntitiesOf(m_CurrentMap)) {
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
