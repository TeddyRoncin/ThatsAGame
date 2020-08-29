#include <string>

#include "map/MapManager.h"
#include "map/Map.h"


Map MapManager::getMap(std::string name) {
	for (Map map : maps) {
		if (map.getName() == name) {
			return map;
		}
	}
	return Map("", 0, 0, nullptr, "");
}