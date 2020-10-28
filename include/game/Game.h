#pragma once

#include "entity/player/Player.h"
#include "entity/npc/Npc.h"
#include "entity/npc/SimpleNpc.h"

#include "renderer/Renderer.h"
#include "inputs/Inputs.h"

#include "map/Map.h"

class Game : public Renderer, public Input
{
public:
	Game();
	~Game();

	void loop();
private:
	Map map;
	Player m_Player;
	std::vector<Npc*> m_Entities;
};
