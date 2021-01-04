#pragma once

#include "test_folder/entity/RenderableEntity.h"

class Map
{
public:
	Map();
	~Map();
public:
	RenderableEntity* operator[](size_t index) const;
	std::vector<RenderableEntity*> GetEntities() const;
	const int Width() const;
	const int Height() const;
	const bool DoesStaticCollide(Entity* entity) const;
private:
	void registerMaps();
	void loadMap(const char* mapName);
private:
	const char* name;
	size_t m_Width, m_Height;
	std::vector<RenderableEntity*> m_Entities;
private:
	int m_CurrentMap;
	std::vector<const char*> m_Maps;
};
