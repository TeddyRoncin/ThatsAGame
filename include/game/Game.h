#pragma once

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
};
