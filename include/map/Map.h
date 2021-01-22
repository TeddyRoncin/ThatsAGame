#pragma once

#include "map/elements/MapElement.h"
#include "entity/MovableEntity.h"
#include "entity/Interactable.h"

class Map
{
public:
	Map();
	~Map();
public:
	MapElement* operator[](size_t index) const;
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
	std::vector<MovableEntity*> m_MovableEntities;
	std::vector<Interactable*> m_Interactables;
private:
	int m_CurrentMap;
	std::vector<const char*> m_Maps;
};
