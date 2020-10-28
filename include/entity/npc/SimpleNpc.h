#pragma once

#include "entity/npc/Npc.h"
#include "map/Maps.h"
#include "entity/npc/ai/PathFinder.h"

class SimpleNpc : public Npc
{

public:
    SimpleNpc(const NewMap& map);
    virtual void update();

private:
    std::vector<std::pair<int, int>> m_PathToTravel;

};
