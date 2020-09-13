#pragma once

#include "entity/npc/Npc.h"
#include "map/Map.h"

class SimpleNpc : public Npc
{

public:
    SimpleNpc(const Map& map);
    virtual void update();

private:
    std::vector<std::pair<int, int>> m_PathToTravel;

};