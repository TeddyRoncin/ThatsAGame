#pragma once

#include <string>
#include <vector>

#include "map/Map.h"

class MapManager 
{
public:
	static Map getMap(std::string name);

	static std::vector<Map> maps;
private:
	MapManager();
};
