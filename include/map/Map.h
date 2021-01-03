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
	const size_t Width() const;
	const size_t Height() const;
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
