#include "pch.h"

#include "map/MapManager.h"
#include "map/EmptyMapElement.h"
#include "map/WallMapElement.h"
<<<<<<< HEAD
#include "entity/Entity.h"
#include "entity/npc/SimpleNpc.h"
#include "bmploader/BMPFile.h"
#include "bmploader/BMPImage.h"

=======
#include "bmploader/BMPFile.h"
#include "bmploader/BMPImage.h"

namespace pt = boost::property_tree;
>>>>>>> github/functionnal
namespace fs = std::filesystem;

bool MapManager::loaded = false;

<<<<<<< HEAD
MapManager::MapManager() :
	m_Maps { { Map("", 0, 0, {} ), {} } }
=======
std::vector<Map> MapManager::maps { Map("", 0, 0, {}, "") };

MapManager::MapManager()
>>>>>>> github/functionnal
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
<<<<<<< HEAD
		if (file.extension().string() == std::string(".bmp")) {
			loadMap(file.relative_path().string());
=======
		if (file.extension().string() == std::string(".json")) {
			MapManager::loadMap(file.relative_path().string());
>>>>>>> github/functionnal
		}
	}
	MapManager::loaded = true;
}

const Map& MapManager::getMap(std::string name)
{
<<<<<<< HEAD
	for (std::pair<const Map&, std::vector<Npc*>> map : m_Maps) {
		std::string n = map.first.getName();
		if (map.first.getName() == name) {
			return map.first;
		}
	}
	return getMap("");
}

std::vector<Npc*> MapManager::getEntitiesOf(const Map& map)
{
	return m_Maps.at(map);
=======
	for (Map& map : maps) {
		if (map.getName() == name) {
			return map;
		}
	}
	return maps[0];
>>>>>>> github/functionnal
}

void MapManager::loadMap(std::string fileName)
{
<<<<<<< HEAD
	std::string mapName = fileName.substr(0, fileName.size() - 4);
	BMPImage image = BMPFile(fileName).load();
	if (image.getWidth() == 0) {
		std::cerr << "Could not load image for map " << fileName << std::endl;
		return;
	}
	std::vector<std::vector<MapElement*>> mapElements;
	std::vector<Npc*> entities;
	for (size_t x(0); x < image.getWidth(); x++) {
		mapElements.push_back(std::vector<MapElement*>());
		for (size_t y(0); y < image.getHeight(); y++) {
			RGBColor color = image.getRGBColor(x, y);
			if ((int) color.R == 255 && (int) color.G == 255) {
				mapElements[x].push_back(new EmptyMapElement());
			} else if (color.R == 0 && color.G == 0) {
				mapElements[x].push_back(new WallMapElement());
			} else {
				std::cerr << "Element unknow on map " << mapName << " at tile position (" << x << ", " << y << "). Skipping loading for this map" << std::endl;
				return;
			}
			if (color.B == 255) {
				SimpleNpc* npc = new SimpleNpc(x, y);
				entities.push_back(npc);
			} 
		}
	}
	//Map map(name, width, height, mapElements, backgroundPath, entities);
	m_Maps.insert({
		Map(mapName, image.getWidth(), image.getHeight(), mapElements),
		entities
	});
=======
	pt::ptree root;
	pt::read_json(fileName, root);
	std::string name = root.get<std::string>("name");
	int width = root.get<int>("width");
	int height = root.get<int>("height");
	std::string backgroundPath = root.get<std::string>("backgroundPath");
	std::string mapPatternFile = root.get<std::string>("map.mapPattern");
	BMPImage image = BMPFile(mapPatternFile).load();
	if (image.getWidth() == 0) {
		// std::cerr << "Could not load image for map " << fileName << std::endl;
		return;
	}
	if (width != image.getWidth()) {
		// std::cerr << "Width of the map is not equal to the width given in the json" << std::endl;
		return;
	}
	if (height != image.getHeight()) {
		// std::cerr << "Height of the map is not equal to the height given in the json" << std::endl;
		return;
	}
	std::vector<std::vector<MapElement*>> mapElements;
	for (size_t x(0); x < width; x++) {
		mapElements.push_back(std::vector<MapElement*>());
		for (size_t y(0); y < height; y++) {
			RGBColor color = image.getRGBColor(x, y);
			if (color == RGBColor{255, 255, 255}) {
				mapElements[x].push_back(new EmptyMapElement());
			} else if (color == RGBColor{0, 0, 0}) {
				mapElements[x].push_back(new WallMapElement());
			} else {
				// std::cerr << "Element unknow on map " << name << " at tile position (" << x << ", " << y << "). Skipping loading for this map" << std::endl;
				return;
			}
		}
	}
	MapManager::maps.push_back(Map(name, width, height, mapElements, backgroundPath));
>>>>>>> github/functionnal
}
