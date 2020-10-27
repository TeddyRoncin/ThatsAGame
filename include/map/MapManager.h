#pragma once

#include "map/Map.h"
#include "entity/npc/Npc.h"

class MapManager 
{
public:
    const Map& getMap(std::string name);
    std::vector<Npc*> getEntitiesOf(const Map& map);

protected:
    MapManager();

private:
    void registerMaps();
    static bool loaded;
    void loadMap(std::string fileName);
    std::map<Map, std::vector<Npc*>> m_Maps;
};