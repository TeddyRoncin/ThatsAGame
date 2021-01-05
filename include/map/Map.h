#pragma once

#include "map/elements/MapElement.h"

#include "test_folder/entity/Entity.h"

class Map
{
public:
	Map();
	~Map();
public:
	MapElement* operator[](size_t index) const;
	std::vector<MapElement*> GetEntities() const;
	const int Width() const;
	const int Height() const;
	const int size() const;
private:
	void registerMaps();
	void loadMap(const char* mapName);
private:
	const char* name;
	size_t m_Width, m_Height;
	std::vector<MapElement*> m_Elements;
private:
	int m_CurrentMap;
	std::vector<const char*> m_Maps;
};
