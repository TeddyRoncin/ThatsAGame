#include "pch.h"

#include "map/MapManager.h"
#include "map/EmptyMapElement.h"
#include "map/WallMapElement.h"
#include "entity/Entity.h"
#include "entity/npc/SimpleNpc.h"
#include "bmploader/BMPFile.h"
#include "bmploader/BMPImage.h"

namespace fs = std::filesystem;

bool MapManager::loaded = false;

MapManager::MapManager() :
	m_Maps { { Map("", 0, 0, {} ), {} } }
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
		if (file.extension().string() == std::string(".bmp")) {
			loadMap(file.relative_path().string());
		}
	}
	MapManager::loaded = true;
}

const Map& MapManager::getMap(std::string name)
{
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
}

void MapManager::loadMap(std::string fileName)
{
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
}
