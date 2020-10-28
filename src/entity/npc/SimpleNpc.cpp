#include "pch.h"

#include "entity/npc/SimpleNpc.h"
#include "entity/Entity.h"
#include "entity/npc/ai/PathFinder.h"

SimpleNpc::SimpleNpc(const NewMap& map) :
    Npc("npc pathfinding Teddy", 0.0f, 400.0f, 200.0f, 200.0f, "assets/textures/test.png")
{
    PathFinder pathFinder(map);
    m_PathToTravel = pathFinder.find(0, 2, 2, 2, this);
    //m_PathToTravel.erase(m_PathToTravel.begin());
}

void SimpleNpc::update()
{
    if (m_PathToTravel.size() == 0) {
        return;
    }
    if (m_pos.getX()/200.0f == m_PathToTravel[0].first &&
        m_pos.getY()/200.0f == m_PathToTravel[0].second) {
        m_PathToTravel.erase(m_PathToTravel.begin());
    }
    if (m_pos.getX()/200.0f == m_PathToTravel[0].first && m_pos.getY()/200.0f < m_PathToTravel[0].second) {
        m_pos.position.second += 0.5f;
        //std::cout << "going up" << std::endl;
    } else if (m_pos.getX()/200.0f == m_PathToTravel[0].first && m_pos.getY()/200.0f > m_PathToTravel[0].second) {
        m_pos.position.second -= 0.5f;
        //std::cout << "going down" << std::endl;
    } else if (m_pos.getX()/200.0f < m_PathToTravel[0].first && m_pos.getY()/200.0f == m_PathToTravel[0].second) {
        //std::cout << "going right" << std::endl;
        m_pos.position.first += 0.5f;
    } else {
        //std::cout << "going left" << std::endl;
        m_pos.position.first -= 0.5f;
    }
}
