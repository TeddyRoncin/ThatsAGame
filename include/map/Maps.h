#pragma once

#include "map/elements/MapElement.h"

class NewMap
{
public:
	NewMap();
	~NewMap();
public:
	MapElement* operator[](size_t index) const;
	const size_t Width() const;
	const size_t Height() const;
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
