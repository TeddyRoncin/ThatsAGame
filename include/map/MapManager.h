#pragma once

#include "map/Map.h"
<<<<<<< HEAD
#include "entity/npc/Npc.h"
=======
>>>>>>> github/functionnal

class MapManager 
{
public:
<<<<<<< HEAD
    const Map& getMap(std::string name);
    std::vector<Npc*> getEntitiesOf(const Map& map);
=======
    static const Map& getMap(std::string name);
>>>>>>> github/functionnal

protected:
    MapManager();

private:
<<<<<<< HEAD
    void registerMaps();
    static bool loaded;
    void loadMap(std::string fileName);
    std::map<Map, std::vector<Npc*>> m_Maps;
=======
    static void registerMaps();
    static bool loaded;
    static void loadMap(std::string fileName);
    static std::vector<Map> maps;
>>>>>>> github/functionnal
};