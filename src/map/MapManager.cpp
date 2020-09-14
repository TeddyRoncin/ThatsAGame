#include "pch.h"

#include "map/MapManager.h"
#include "map/EmptyMapElement.h"
#include "map/WallMapElement.h"
#include "bmploader/BMPFile.h"
#include "bmploader/BMPImage.h"

namespace pt = boost::property_tree;
namespace fs = std::filesystem;

bool MapManager::loaded = false;

std::vector<Map> MapManager::maps { Map("", 0, 0, {}, "") };

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
	for (fs::path file : fs::directory_iterator(PATH)) {
		if (file.extension().string() == std::string(".json")) {
			MapManager::loadMap(file.relative_path().string());
		}
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
	return maps[0];
}

void MapManager::loadMap(std::string fileName)
{
	pt::ptree root;
	pt::read_json(fileName, root);
	std::string name = root.get<std::string>("name");
	int width = root.get<int>("width");
	int height = root.get<int>("height");
	std::string backgroundPath = root.get<std::string>("backgroundPath");
	std::string mapPatternFile = root.get<std::string>("map.mapPattern");
	BMPImage image = BMPFile(mapPatternFile).load();
	if (image.getWidth() == 0) {
		std::cerr << "Could not load image for map " << fileName << std::endl;
		return;
	}
	if (width != image.getWidth()) {
		std::cerr << "Width of the map is not equal to the width given in the json" << std::endl;
		return;
	}
	if (height != image.getHeight()) {
		std::cerr << "Height of the map is not equal to the height given in the json" << std::endl;
		return;
	}
	std::vector<std::vector<MapElement*>> mapElements;
	for (size_t y(0); y < width; y++) {
		mapElements.push_back(std::vector<MapElement*>());
		for (size_t x(0); x < height; x++) {
			RGBColor color = image.getRGBColor(x, y);
			if (color == RGBColor{255, 255, 255}) {
				mapElements[x].push_back(new EmptyMapElement());
			} else if (color == RGBColor{0, 0, 0}) {
				mapElements[x].push_back(new WallMapElement());
			} else {
				std::cerr << "Element unknow on map " << name << " at tile position (" << x << ", " << y << "). Skipping loading for this map" << std::endl;
				return;
			}
		}
	}
	MapManager::maps.push_back(Map(name, width, height, mapElements, backgroundPath));
}
