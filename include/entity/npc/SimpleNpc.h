#pragma once

#include "entity/npc/Npc.h"
#include "map/Map.h"
#include "entity/npc/ai/PathFinder.h"

class SimpleNpc : public Npc
{

public:
    SimpleNpc(int x, int y);
    void addPathFinder(const PathFinder& pathFinder);
    virtual void update();



};
