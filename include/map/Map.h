#pragma once

#include "map/MapElement.h"
#include "entity/Entity.h"

class Map
{

public:
    Map(std::string name, int width, int height, std::vector<std::vector<MapElement*>> elements, std::string backgroundPath);
    Map(Map& map);
    Map(const Map& map);
    Map(Map&& map);
    ~Map();
    std::string getName() const;
    std::string getBackgroundPath() const;
    int getWidth() const;
    int getHeight() const;
    bool canEntityMoveAt(int x, int y, Entity* entity) const;
    MapElement* getAt(int x, int y) const;
    std::vector<std::vector<MapElement*>> getMapElements() const;

private:
    std::string m_Name;
    int m_Width;
    int m_Height;
    std::vector<std::vector<MapElement*>> m_Elements;
    std::string m_BackgroundPath;

};