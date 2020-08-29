#pragma once

#include <string>
#include <vector>

#include "map/Map.h"

namespace MapManager {

	std::vector<Map> maps;
	Map getMap(std::string name);

};