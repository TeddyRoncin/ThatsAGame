#pragma once

#include "map/Map.h"

class MapManager 
{
public:
    static std::vector<Map> maps;
    static const Map& getMap(std::string name);
private:
    static void registerMaps();
    static bool loaded;
    static void loadMap(std::string fileName);

protected:
    MapManager();
};