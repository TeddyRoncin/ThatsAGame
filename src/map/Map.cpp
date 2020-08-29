#include <iostream>
#include <string>

#include "map/Map.h"

Map::Map(std::string name, int width, int height, MapElement** elements, std::string backgroundPath) :
    m_Name(name),
    m_Width(width),
    m_Height(height),
    m_Elements(elements),
    m_BackgroundPath(backgroundPath)
{

}

Map::~Map() {
    for (size_t i = 0; i < m_Width; i++) {
        delete[] m_Elements[i];
    }
    delete m_Elements;
}

std::string Map::getName() {
    return m_Name;
}

std::string Map::getBackgroundPath() {
    return m_BackgroundPath;
}

bool Map::canEntityMoveAt(int x, int y, Entity entity) {
    return m_Elements[x][y].canEntityMoveOn(entity);
}