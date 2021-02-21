#include "pch.h"

#include "map/Map.h"

#include "map/elements/EmptyMapElement.h"
#include "map/elements/WallMapElement.h"

#include "bmploader/BMPFile.h"
#include "bmploader/BMPImage.h"

#include "entity/Player.h"
#include "entity/EntityId.h"

namespace pt = boost::property_tree;

const char* Map::m_Name(nullptr);
size_t Map::m_Width(0);
size_t Map::m_Height(0);

Map::Map()
	:m_CurrentMap(0)
{
	registerMaps();
	loadMap(m_Maps[m_CurrentMap]);
	// m_MovableElements.push_back(new Player({0, 0}));//, [this](MovableEntity* entity) -> bool {return this[entity->GetY() * this->m_Width + entity->GetX()];}));
}

Map::~Map()
{
	for(MapElement* elem : m_Elements)
	{
		delete elem;
	}
	for (MovableEntity* entity : m_MovableElements)
	{
		delete entity;
	}
	for (Interactable* interactable : m_InteractableElements)
	{
		delete interactable;
	}
}

MapElement* Map::operator[](size_t index) const
{
	return m_Elements[index];
}

void Map::Tick()
{
	for(auto movable : m_MovableElements) {
		auto[x, y] = movable->GetPosition().getPosition();
		auto[width, height] = movable->GetSize().getDimension();
		(*movable)(*m_Elements[static_cast<int>(x) + static_cast<int>(y) * m_Width]);
		(*movable)(*m_Elements[static_cast<int>(x + width) + static_cast<int>(y) * m_Width]);
		(*movable)(*m_Elements[static_cast<int>(x) + static_cast<int>(y + height) * m_Width]);
		(*movable)(*m_Elements[static_cast<int>(x + width) + static_cast<int>(y + height) * m_Width]);
		for(auto interactable : m_InteractableElements) {
			(*movable)(*interactable);
		}
		movable->Tick();
	}
}

const char* const Map::Name()
{
	return m_Name;
}

const int Map::Width()
{
	return m_Width;
}

const int Map::Height()
{
	return m_Height;
}

const int Map::size()
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
			// rgb : MapElement MovableElements InteractableElements
			RGBColor color = pattern.getRGBColor(x, y);

			// MapElement : Red value
			switch (color.R)
			{
				case GET_COLOR_OF_MAP_ELEMENT(static_cast<int>(EntityId::None)):
					std::cerr << "Cannot have an empty space in map elements grid" << std::endl;
					break;
				case GET_COLOR_OF_MAP_ELEMENT(static_cast<int>(EntityId::EmptyMapElement)):
					m_Elements.emplace_back(new EmptyMapElement({static_cast<float>(x), static_cast<float>(y)}));
					break;
				case GET_COLOR_OF_MAP_ELEMENT(static_cast<int>(EntityId::WallMapElement)):
					m_Elements.emplace_back(new WallMapElement({static_cast<float>(x), static_cast<float>(y)}));
					break;
				default:
					std::cerr << "Color(" << static_cast<int>(color.R) << ", " << static_cast<int>(color.G) << ", " << static_cast<int>(color.B) << ")\n";
					std::cerr << "Element unknown on map " << std::string(name) << " at tile position (" << x << ", " << y << "). Skipping loading for this map" << std::endl;
					// return; ?
			}

			// MovableElements : Green value
			switch (color.G)
			{
				case GET_COLOR_OF_MOVABLE_ENTITY(static_cast<int>(EntityId::None)):
					break;
				case GET_COLOR_OF_MOVABLE_ENTITY(static_cast<int>(EntityId::Player)):
					m_MovableElements.push_back(new Player({static_cast<float>(x), static_cast<float>(y)}));
					break;
				default:
					std::cerr << "Color(" << static_cast<int>(color.R) << ", " << static_cast<int>(color.G) << ", " << static_cast<int>(color.B) << ")\n";
					std::cerr << "MovableEntity unknown on map " << std::string(name) << " at position (" << x << ", " << y << "). Skipping loading for this map" << std::endl;
					// return; ?
			}
		}
	}
}
