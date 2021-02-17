#pragma once

#include "map/elements/MapElement.h"
#include "map/elements/InteractableElement.h"

#include "entity/EntityManager.h"
#include "entity/MovableEntity.h"

class Map : public EntityManager
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
	void Tick();
private:
	void registerMaps();
	void loadMap(const char* mapName);
private:
	static const char* m_Name;
	static size_t m_Width, m_Height;
private:
	std::vector<MapElement*> m_Elements;
	std::vector<MovableEntity*> m_MovableElements;
	std::vector<InteractableElement*> m_InteractableElements;
private:
	int m_CurrentMap;
	std::vector<const char*> m_Maps;
};
