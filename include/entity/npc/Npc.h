#pragma once

#include "entity/Renderable.h"
#include "entity/npc/ai/PathFinder.h"


class Npc : public Renderable
{
public:
    Npc(const char* name, float x, float y, float width, float height, const char* sprite);
    virtual void update() = 0;
    void addPathFinder(const PathFinder& pathFinder);

protected:
    std::vector<std::pair<int, int>> m_PathToTravel;

};
