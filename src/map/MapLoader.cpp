#include <iostream>
#include <map>
#include <filesystem>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "map/Map.h"
#include "map/MapLoader.h"
#include "map/MapManager.h"
#include "map/MapElement.h"
#include "map/EmptyMapElement.h"
#include "map/WallMapElement.h"

namespace pt = boost::property_tree;
namespace fs = std::filesystem;

void MapLoader::registerMaps()
{
	const std::string PATH = "assets/maps/";
	for (fs::directory_entry file : fs::directory_iterator(PATH)) {
		MapLoader loader(file.path().string());
		loader.loadMap();
	}
}

MapLoader::MapLoader(std::string fileName) :
	m_FileName(fileName)
{
}

void MapLoader::loadMap()
{
	pt::ptree root;
	pt::read_json(m_FileName, root);
	std::string name = root.get<std::string>("name");
	int width = root.get<int>("width");
	int height = root.get<int>("height");
	std::string backgroundPath = root.get<std::string>("backgroundPath");
	std::map<std::string, std::string> tiles;
	for (pt::ptree::value_type& tileObj : root.get_child("map.tiles")) {
		tiles[tileObj.second.get<std::string>("tile")] = tileObj.second.get<std::string>("value");
	}
	std::vector<std::vector<MapElement*>> mapElements;
	for (int x = 0; x < width; x++) {
		mapElements.push_back(std::vector<MapElement*>());
	}
	int y(0);
	for (pt::ptree::value_type& row : root.get_child("map.mapPattern")) {
		int x(0);
		for (pt::ptree::value_type& cell : row.second) {
			std::string mapElementName = tiles[cell.second.get_value<std::string>()];
			if (mapElementName == "EMPTY") {
				mapElements[x].push_back(new EmptyMapElement());
			} else if (mapElementName == "WALL") {
				mapElements[x].push_back(new WallMapElement());
			}
			x++;
		}
		if (x != width) {
			std::cerr << "Width of the map is not equal to the width given in the json" << std::endl;
			return;
		}
		y++;
	}
	if (y != height) {
		std::cerr << "Height of the map is not equal to the height given in the json" << std::endl;
		return;
	}
	MapManager::maps.push_back(Map(name, width, height, mapElements, backgroundPath));
}