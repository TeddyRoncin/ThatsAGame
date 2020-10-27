#pragma once

#include "entity/player/Player.h"
#include "entity/npc/Npc.h"
#include "entity/npc/SimpleNpc.h"

#include "renderer/Renderer.h"
#include "inputs/Inputs.h"

#include "map/MapManager.h"

class Game : public Renderer, public Input, public MapManager
{
public:
	Game();
	~Game();

	void loop();
private:
	Map m_CurrentMap;
	Player m_Player;
	std::vector<Npc*> m_Entities;
};
