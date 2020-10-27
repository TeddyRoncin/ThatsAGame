#include "pch.h"

#include "entity/npc/Npc.h"

Npc::Npc(const char* name, float x, float y, float width, float height, const char* sprite) :
    Renderable(name, x, y, width, height, sprite)
{

}

void Npc::addPathFinder(const PathFinder& pathFinder)
{
    m_PathToTravel = pathFinder.find(std::floor(m_pos.getX()), std::floor(m_pos.getY()), 2, 2, this);
}
