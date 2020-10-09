#include "pch.h"

#include "map/Map.h"

Map::Map(std::string name, int width, int height, std::vector<std::vector<MapElement*>> elements, std::string backgroundPath, std::vector<Npc*> entities) :
    m_Name(name),
    m_Width(width),
    m_Height(height),
    m_Elements(elements),
    m_BackgroundPath(backgroundPath),
    m_Entities(entities)
{
}

Map::Map(const Map& map)
    :m_Name(map.m_Name),
    m_Width(map.m_Width),
    m_Height(map.m_Height),
    m_BackgroundPath(map.m_BackgroundPath)
{
    for (int x = 0; x < m_Width; x++) {
        m_Elements.push_back(std::vector<MapElement*>());
        for (int y = 0; y < m_Height; y++) {
            m_Elements[x].push_back(map.m_Elements[x][y]);
        }
    }
}

Map::Map(Map&& map)
    :m_Name(map.m_Name), m_Width(map.m_Width), m_Height(map.m_Height), m_BackgroundPath(map.m_BackgroundPath) 
{
    for (int x = 0; x < m_Width; x++) {
        m_Elements.push_back(std::vector<MapElement*>());
        for (int y = 0; y < m_Height; y++) {
            m_Elements[x].push_back(map.m_Elements[x][y]);
            map.m_Elements[x][y] = nullptr;
        }
    }
    for (int i = 0; i < m_Width; i++) {
        m_Entities.push_back(map.m_Entities[i]);
        map.m_Entities[i] = nullptr;
    }
}

Map::~Map()
{
    for (int x(0); x < m_Elements.size(); x++) {
        for (int y(0); y < m_Elements[x].size(); y++) {
            //if (m_Elements[x][y] != nullptr) {
            delete m_Elements[x][y];
            //}
        }
    }
    for (int i = 0; i < m_Entities.size(); i++) {
        if (m_Entities[i] != nullptr) {
            delete m_Entities[i];
        }
    }
}

std::string Map::getName() const
{
    return m_Name;
}

std::string Map::getBackgroundPath() const
{
    return m_BackgroundPath;
}

std::vector<Npc*> Map::getEntities() const
{
    std::cout << "on les envoie ! : " <<  m_Entities.size() << std::endl;
    return m_Entities;
}

bool Map::canEntityMoveAt(int x, int y, Entity* entity) const
{
    return m_Elements[x][y]->canEntityMoveOn(entity);
}

MapElement* Map::getAt(int x, int y) const
{
    if (x < 0 || x >= m_Width || y < 0 || y >= m_Height) {
        return nullptr;
    }
    return m_Elements[x][y];
}

int Map::getWidth() const
{
    return m_Width;
}

int Map::getHeight() const
{
    return m_Height;
}

std::vector<std::vector<MapElement*>> Map::getMapElements() const
{
    return m_Elements;
}