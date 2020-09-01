#pragma once

#include <filesystem>

#include "map/MapManager.h"
#include "map/MapElement.h"
#include "map/EmptyMapElement.h"
#include "map/Map.h"

class MapLoader 
{
public:
    static void registerMaps();

private:
    MapLoader();
    MapLoader(std::string fileName);
    void loadMap();

private:
    std::string m_FileName;

};
