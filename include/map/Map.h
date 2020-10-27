#pragma once

#include "map/MapElement.h"

class Map
{

public:
    Map(std::string name, int width, int height, std::vector<std::vector<MapElement*>> elements);
    Map(Map& map);
    Map(const Map& map);
    Map(Map&& map);
    ~Map();
    std::string getName() const;
    std::string getBackgroundPath() const;
    int getWidth() const;
    int getHeight() const;
    MapElement* getAt(int x, int y) const;
    std::vector<std::vector<MapElement*>> getMapElements() const;

private:
    std::string m_Name;
    int m_Width;
    int m_Height;
    std::vector<std::vector<MapElement*>> m_Elements;

};
