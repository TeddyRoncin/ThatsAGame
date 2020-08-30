#pragma once

#include <vector>
#include <fstream>
#include <filesystem>
#include <string>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "MapManager.h"
#include "MapElement.h"
#include "EmptyMapElement.h"
#include "Wall.h"
#include "Map.h"

class MapLoader 
{
public:
    static void registerMaps();

    private:
    MapLoader();
    MapLoader(std::string fileName);
    void loadMap();

private:
    std::string& m_FileStream;

};
