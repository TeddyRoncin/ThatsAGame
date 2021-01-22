#include "pch.h"

#include "map/Map.h"
#include "map/elements/MapElementType.h"
#include "map/elements/EmptyMapElement.h"
#include "map/elements/WallMapElement.h"
#include "bmploader/BMPFile.h"
#include "bmploader/BMPImage.h"
#include "entity/Player.h"

namespace pt = boost::property_tree;

Map::Map()
	:m_CurrentMap(0)
{
	registerMaps();
	loadMap(m_Maps[m_CurrentMap]);
	m_MovableEntities.push_back(new Player({0, 0}));//, [this](MovableEntity* entity) -> bool {return this[entity->GetY() * this->m_Width + entity->GetX()];}));
}

Map::~Map()
{
	for(MapElement* elem : m_Elements)
	{
		delete elem;
	}
	for (MovableEntity* entity : m_MovableEntities)
	{
		delete entity;
	}
	for (Interactable* interactable : m_Interactables)
	{
		delete interactable;
	}
}

MapElement* Map::operator[](size_t index) const
{
	return m_Elements[index];
}

const int Map::Width() const
{
	return m_Width;
}

const int Map::Height() const
{
	return m_Height;
}

const int Map::size() const
{
	return m_Width * m_Height;
}

void Map::registerMaps()
{
	pt::ptree registry;
	pt::read_json("assets/maps/register.json", registry);
	int number = registry.get<int>("mapNumber");
	m_Maps.reserve(number);
	for(pt::ptree::value_type map : registry.get_child("maps"))
	{
		m_Maps.emplace_back(map.second.data().c_str());
	}
}

void Map::loadMap(const char* name)
{
	pt::ptree maps;
	std::string map("assets/maps/"); map += std::string(name) += std::string(".json");
	pt::read_json(map, maps);

	m_Width = maps.get<int>("width");
	m_Height = maps.get<int>("height");

	m_Elements.reserve(m_Width * m_Height);

	BMPImage pattern = BMPFile(maps.get<std::string>("mapPattern")).load();

	if (pattern.getWidth() == 0 || pattern.getHeight() == 0) {
		std::cerr << "Could not load image for map " << name << std::endl;
		return;
	}
	if (m_Width != pattern.getWidth()) {
		std::cerr << "Width of the map is not equal to the width given in the json" << std::endl;
		return;
	}
	if (m_Height != pattern.getHeight()) {
		std::cerr << "Height of the map is not equal to the height given in the json" << std::endl;
		return;
	}

	for (int y(0); y < m_Height; y++) {
		for (int x(0); x < m_Width; x++) {
			// rgb : MapElement MovableEntities InteractableEntities
			RGBColor color = pattern.getRGBColor(x, y);

			// MapElement
			if (color.R == static_cast<int>(MapElementType::EmptyMapElement)) {
				m_Elements.emplace_back(new EmptyMapElement({static_cast<float>(x), static_cast<float>(y)}));
			} else if (color.R == static_cast<int>(MapElementType::WallMapElement)) {
				m_Elements.emplace_back(new WallMapElement({ static_cast<float>(x), static_cast<float>(y)}));
			} else {
				std::cerr << "Element unknow on map " << name << " at tile position (" << x << ", " << y << "). Skipping loading for this map" << std::endl;
				return;
			}

			// MoveableEntities

			// InteractableEntities

		}
	}
}
