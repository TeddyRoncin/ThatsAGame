#pragma once

#include "map/elements/MapElement.h"
#include "entity/MovableEntity.h"
#include "entity/Interactable.h"

class Map
{
public:
	static const char* const Name();
	static const int Width();
	static const int Height();
	static const int size();
public:
	Map();
	~Map();
public:
	MapElement* operator[](size_t index) const;
private:
	void registerMaps();
	void loadMap(const char* mapName);
private:
	static const char* m_Name;
	static size_t m_Width, m_Height;
private:
	std::vector<MapElement*> m_Elements;
	std::vector<MovableEntity*> m_MovableEntities;
	std::vector<Interactable*> m_Interactables;
private:
	int m_CurrentMap;
	std::vector<const char*> m_Maps;
};
