#pragma once

#include "map/MapElement.h"
<<<<<<< HEAD
=======
#include "entity/Entity.h"
>>>>>>> github/functionnal

class Map
{

public:
<<<<<<< HEAD
    Map(std::string name, int width, int height, std::vector<std::vector<MapElement*>> elements);
=======
    Map(std::string name, int width, int height, std::vector<std::vector<MapElement*>> elements, std::string backgroundPath);
>>>>>>> github/functionnal
    Map(Map& map);
    Map(const Map& map);
    Map(Map&& map);
    ~Map();
    std::string getName() const;
    std::string getBackgroundPath() const;
    int getWidth() const;
    int getHeight() const;
<<<<<<< HEAD
=======
    bool canEntityMoveAt(int x, int y, Entity* entity) const;
>>>>>>> github/functionnal
    MapElement* getAt(int x, int y) const;
    std::vector<std::vector<MapElement*>> getMapElements() const;

private:
    std::string m_Name;
    int m_Width;
    int m_Height;
    std::vector<std::vector<MapElement*>> m_Elements;
<<<<<<< HEAD

};
=======
    std::string m_BackgroundPath;

};
>>>>>>> github/functionnal
