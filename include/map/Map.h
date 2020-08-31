#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "map/MapElement.h"
#include "entity/Entity.h"

class Map
{

public:
    Map(std::string name, int width, int height, std::vector<std::vector<MapElement*>>, std::string backgroundPath);
    Map(const Map& map);
    ~Map();
    std::string getName() const;
    std::string getBackgroundPath() const;
    bool canEntityMoveAt(int x, int y, Entity entity);
    MapElement* getAt(int x, int y);

private:
    std::string m_Name;
    int m_Width;
    int m_Height;
    std::vector<std::vector<MapElement*>> m_Elements;
    std::string m_BackgroundPath;

};