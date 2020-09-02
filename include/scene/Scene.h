#pragma once

#include "map/Map.h"

class Scene
{
public:
	Scene(const Map& map);
private:

	Map m_currentMap;

	Scene() = default;
	Scene(const Scene&) = default;
};