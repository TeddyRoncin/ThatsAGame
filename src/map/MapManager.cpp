#include "pch.h"

#include "map/MapManager.h"
#include "map/EmptyMapElement.h"
#include "map/WallMapElement.h"
#include "utils/Utils.h"

namespace pt = boost::property_tree;
namespace fs = std::filesystem;

bool MapManager::loaded = false;

std::vector<Map> MapManager::maps {};

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

Map& MapManager::getMap(std::string name)
{
	for (Map& map : maps) {
		if (map.getName() == name) {
			return map;
		}
	}
	Map emptyMap("", 0, 0, std::vector<std::vector<MapElement*>>(), "");
	return emptyMap;
}

void MapManager::loadMap(std::string fileName)
{
	pt::ptree root;
	pt::read_json(fileName, root);
	std::string name = root.get<std::string>("name");
	int width = root.get<int>("width");
	int height = root.get<int>("height");
	std::string backgroundPath = root.get<std::string>("backgroundPath");
	const char* mapPatternFile = root.get<std::string>("map.mapPattern").c_str();
	SDL_Surface* image = IMG_Load(root.get<std::string>("map.mapPattern").c_str());
	std::cout << SDL_LockSurface(image) << std::endl;
	if (!image) {
		std::cerr << "Could not load image : " << IMG_GetError() << std::endl;
		return;
	}
	if (width != image->w) {
		std::cerr << "Width of the map is not equal to the width given in the json" << std::endl;
		return;
	}
	if (height != image->h) {
		std::cerr << "Height of the map is not equal to the height given in the json" << std::endl;
		return;
	}
	std::vector<std::vector<MapElement*>> mapElements;
	for (int x = 0; x < width; x++) {
		mapElements.push_back(std::vector<MapElement*>());
	}
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			RGBColor color = getPixelColor(image, x, y);
			if (color == RGBColor{255, 255, 255}) {
				mapElements[x].push_back(new EmptyMapElement());
			} else if (color == RGBColor{0, 0, 0}) {
				mapElements[x].push_back(new WallMapElement());
			} else {
				std::cout << color.R << " " << color.G << " " << color.B << std::endl;
			}
		}
	}
	SDL_FreeSurface(image);
	image = nullptr;
	MapManager::maps.push_back(Map(name, width, height, mapElements, backgroundPath));
}
