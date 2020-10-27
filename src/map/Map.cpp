#include "pch.h"

#include "map/Map.h"

<<<<<<< HEAD
Map::Map(std::string name, int width, int height, std::vector<std::vector<MapElement*>> elements) :
    m_Name(name),
    m_Width(width),
    m_Height(height),
    m_Elements(elements)
{
    for (int x = 0; x < m_Width; x++) {
        for (int y = 0; y < m_Height; y++) {
            m_Elements[x][y]->getTexturePath();
        }
    }
=======
Map::Map(std::string name, int width, int height, std::vector<std::vector<MapElement*>> elements, std::string backgroundPath) :
    m_Name(name),
    m_Width(width),
    m_Height(height),
    m_Elements(elements),
    m_BackgroundPath(backgroundPath)
{
>>>>>>> github/functionnal
}

Map::Map(const Map& map)
    :m_Name(map.m_Name),
    m_Width(map.m_Width),
<<<<<<< HEAD
    m_Height(map.m_Height)
=======
    m_Height(map.m_Height),
    m_BackgroundPath(map.m_BackgroundPath)
>>>>>>> github/functionnal
{
    for (int x = 0; x < m_Width; x++) {
        m_Elements.push_back(std::vector<MapElement*>());
        for (int y = 0; y < m_Height; y++) {
            m_Elements[x].push_back(map.m_Elements[x][y]);
        }
    }
}

Map::Map(Map&& map)
<<<<<<< HEAD
    :m_Name(map.m_Name), m_Width(map.m_Width), m_Height(map.m_Height)
=======
    :m_Name(map.m_Name), m_Width(map.m_Width), m_Height(map.m_Height), m_BackgroundPath(map.m_BackgroundPath) 
>>>>>>> github/functionnal
{
    for (int x = 0; x < m_Width; x++) {
        m_Elements.push_back(std::vector<MapElement*>());
        for (int y = 0; y < m_Height; y++) {
            m_Elements[x].push_back(map.m_Elements[x][y]);
            map.m_Elements[x][y] = nullptr;
        }
    }
}

Map::~Map()
{
    for (int x(0); x < m_Elements.size(); x++) {
        for (int y(0); y < m_Elements[x].size(); y++) {
<<<<<<< HEAD
            if (m_Elements[x][y] != nullptr) {
                delete m_Elements[x][y];
            }
=======
            delete m_Elements[x][y];
>>>>>>> github/functionnal
        }
    }
}

std::string Map::getName() const
{
    return m_Name;
}

<<<<<<< HEAD
/*bool Map::canEntityMoveAt(int x, int y, Entity* entity) const
{
    return m_Elements[x][y]->canEntityMoveOn(entity);
}*/
=======
std::string Map::getBackgroundPath() const
{
    return m_BackgroundPath;
}

bool Map::canEntityMoveAt(int x, int y, Entity* entity) const
{
    return m_Elements[x][y]->canEntityMoveOn(entity);
}
>>>>>>> github/functionnal

MapElement* Map::getAt(int x, int y) const
{
    if (x < 0 || x >= m_Width || y < 0 || y >= m_Height) {
        return nullptr;
    }
<<<<<<< HEAD
    m_Elements[x][y]->getTexturePath();
=======
>>>>>>> github/functionnal
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
<<<<<<< HEAD
}


/*const Map& Map::copy() const
{
    return Map(this);
}*/

std::string Map::getBackgroundPath() const
{
    return "";
}
=======
}
>>>>>>> github/functionnal
