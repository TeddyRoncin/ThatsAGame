#pragma once

#include <string>

#include "map/MapElement.h"

class Map {

    public:
    Map(std::string name, int width, int height, MapElement** elements, std::string backgroundPath);
    ~Map();
    std::string getName();
    std::string getBackgroundPath();
    bool canEntityMoveAt(int x, int y, Entity entity);

    private:
    std::string m_Name;
    int m_Width;
    int m_Height;
    MapElement** m_Elements;
    std::string m_BackgroundPath;



};