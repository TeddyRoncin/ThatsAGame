#pragma once

#include "map/Map.h"

class MapManager 
{
public:
    const Map& getMap(std::string name);

protected:
    MapManager();

private:
    void registerMaps();
    static bool loaded;
    void loadMap(std::string fileName);
    std::vector<Map> m_Maps;
};