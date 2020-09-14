#include "pch.h"

#include "entity/npc/SimpleNpc.h"
#include "entity/Entity.h"
#include "entity/npc/ai/PathFinder.h"

SimpleNpc::SimpleNpc(const Map& map) :
    Npc("salut", 0, 2, 40, 40, "assets/textures/test.png")
{
    PathFinder pathFinder(map);
    m_PathToTravel = pathFinder.find(0, 2, 2, 2, this);
}

void SimpleNpc::update()
{
    if (m_PathToTravel.size() == 0) {
        return;
    }
    if (m_pos.getX() == m_PathToTravel[0].first && m_pos.getY() < m_PathToTravel[0].second) {
        m_pos.position.second += 0.02;
    } else if (m_pos.getX() == m_PathToTravel[0].first && m_pos.getY() > m_PathToTravel[0].second) {
        m_pos.position.second -= 0.02;
    } else if (m_pos.getX() < m_PathToTravel[0].first && m_pos.getY() == m_PathToTravel[0].second) {
        m_pos.position.first += 0.02;
    } else {
        m_pos.position.first -= 0.02;
    }
    if (m_pos.getX() == m_PathToTravel[0].first && m_pos.getY() == m_PathToTravel[0].second) {
        m_PathToTravel.erase(m_PathToTravel.begin());
    }
    std::cout << m_pos.getX() << "   " << m_pos.getY() << std::endl;
}
