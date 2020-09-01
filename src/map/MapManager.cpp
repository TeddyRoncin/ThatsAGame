#include "pch.h"

#include "map/MapManager.h"

std::vector<Map> MapManager::maps {};

Map MapManager::getMap(std::string name) {
	for (Map map : maps) {
		if (map.getName() == name) {
			return map;
		}
	}
	return Map("", 0, 0, std::vector<std::vector<MapElement*>>(), "");
}
