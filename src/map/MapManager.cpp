#include "pch.h"

#include "map/MapManager.h"
#include "map/EmptyMapElement.h"
#include "map/WallMapElement.h"

namespace pt = boost::property_tree;
namespace fs = std::filesystem;

bool MapManager::loaded = false;

std::vector<Map> MapManager::maps {};

MapManager::MapManager()
{
	registerMaps();
}

void MapManager::registerMaps()
{
	if (MapManager::loaded) {
		return;
	}
	const std::string PATH = "assets/maps/";
	for (fs::directory_entry file : fs::directory_iterator(PATH)) {
		MapManager::loadMap(file.path().string());
	}
	MapManager::loaded = true;
}

const Map& MapManager::getMap(std::string name)
{
	for (Map& map : maps) {
		if (map.getName() == name) {
			return map;
		}
	}
	return Map("", 0, 0, std::vector<std::vector<MapElement*>>(), "");
}

void MapManager::loadMap(std::string fileName)
{
	pt::ptree root;
	pt::read_json(fileName, root);
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
			} else {
				std::cerr << "No Element Here !" << std::endl;
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
