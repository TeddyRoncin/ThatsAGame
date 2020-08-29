#include <filesystem>
#include <string>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "map/Map.h"
#include "map/MapLoader.h"
#include "map/MapManager.h"
#include "map/MapElement.h"
#include "map/EmptyMapElement.h"
#include "map/Wall.h"

namespace pt = boost::property_tree;


void MapLoader::registerMaps()
{
    const std::string PATH = "assets/maps/";
    std::vector<MapLoader> loaders;
    for (std::filesystem::directory_entry file : std::filesystem::directory_iterator(PATH)) {
        MapLoader loader(file.path());
        loader.loadMap();
        loaders.push_back(loader);
    }
}

MapLoader::MapLoader(std::string fileName) :
    m_FileStream(fileName)
{}

void MapLoader::loadMap()
{
    pt::ptree root;
    pt::read_json(m_FileStream, root);
    std::string name = root.get<std::string>("name");
    int width = root.get<int>("width");
    int height = root.get<int>("width");
    std::string backgroundPath = root.get<std::string>("backgroundPath");
    std::map<std::string, std::string> tiles;
    for (pt::ptree::value_type& tileObj : root.get_child("map.tiles")) {
        tiles[tileObj.second.get<std::string>("tile")] = tileObj.second.get<std::string>("value");
    }
    MapElement** mapElements;
    int x(0);
    for (pt::ptree::value_type& row : root.get_child("map.map_pattern")) {
        int y(0);
        for (pt::ptree::value_type& cell : row.second) {
            std::string mapElementName = tiles[cell.second.get_value<std::string>()];
            if (mapElementName == "EMPTY") {
                mapElements[x][y] = EmptyMapElement();
            } else if (mapElementName == "WALL") {
                mapElements[x][y] = Wall();
            }
            y++;
        }
        x++;
    }
    Map map(name, width, height, mapElements, backgroundPath);
    MapManager::maps.push_back(map);
}