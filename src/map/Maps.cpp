#include "pch.h"

#include "map/Maps.h"
#include "map/elements/EmptyMapElement.h"
#include "map/elements/WallMapElement.h"
#include "bmploader/BMPFile.h"
#include "bmploader/BMPImage.h"

namespace pt = boost::property_tree;

NewMap::NewMap()
	:m_CurrentMap(0)
{
	registerMaps();
	loadMap(m_Maps[m_CurrentMap]);
}

NewMap::~NewMap()
{
	for(auto elem : m_Elements)
	{
		delete elem;
	}
}

MapElement* NewMap::operator[](size_t index) const
{
	return m_Elements[index];
}

const size_t NewMap::Width() const
{
	return m_Width;
}

const size_t NewMap::Height() const
{
	return m_Height;
}

void NewMap::registerMaps()
{
	pt::ptree registry;
	pt::read_json("assets/maps/register.json", registry);
	int number = registry.get<int>("mapNumber");
	m_Maps.reserve(number);
	for(pt::ptree::value_type map : registry.get_child("maps"))
	{
		m_Maps.emplace_back(map.second.data().c_str());
	}
	// for(size_t i(0); i < number; i++)
	// {
	// 	m_Maps.emplace_back(registry.get_child("maps"));
	// }
}

void NewMap::loadMap(const char* name)
{
	pt::ptree maps;
	std::string map("assets/maps/");  map += name;
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

	for (size_t x(0); x < m_Width; x++) {
		for (size_t y(0); y < m_Height; y++) {
			RGBColor color = pattern.getRGBColor(x, y);
			if ((int) color.R == 255 && (int) color.G == 255) {
				m_Elements.emplace_back(new EmptyMapElement(/*maybe give it a size from the width and height of the map*/));
			} else if (color.R == 0 && color.G == 0) {
				m_Elements.emplace_back(new WallMapElement(/*same as the upon element*/));
			} else {
				std::cerr << "Element unknow on map " << name << " at tile position (" << x << ", " << y << "). Skipping loading for this map" << std::endl;
				return;
			}
		}
	}
}
