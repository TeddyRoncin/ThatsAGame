#pragma once

#include "map/Map.h"

class MapManager 
{
public:
    static void registerMaps();
    static const Map& getMap(std::string name);

private:
    static bool loaded;
    static std::vector<Map> maps;
    static void loadMap(std::string fileName);

private:
    MapManager();
};