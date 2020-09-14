#include "pch.h"

#include "entity/npc/SimpleNpc.h"
#include "entity/Entity.h"
#include "entity/npc/ai/PathFinder.h"

SimpleNpc::SimpleNpc(const Map& map) :
    Npc("salut", 0, 2, 0.5, 0.5, "assets/textures/test.png")
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
    if (m_pos.getX() == m_PathToTravel[0].first && m_pos.getY() < m_PathToTravel[0].second) {
        m_pos.position.second += 0.02;
        std::cout << "going up" << std::endl;
    } else if (m_pos.getX() == m_PathToTravel[0].first && m_pos.getY() > m_PathToTravel[0].second) {
        m_pos.position.second -= 0.02;
        std::cout << "going down" << std::endl;
    } else if (m_pos.getX() < m_PathToTravel[0].first && m_pos.getY() == m_PathToTravel[0].second) {
        std::cout << "going right" << std::endl;
        m_pos.position.first += 0.02;
    } else {
        std::cout << "going left" << std::endl;
        m_pos.position.first -= 0.02;
    }
    if (std::round(m_pos.getX() * 100) == std::round(m_PathToTravel[0].first * 100) &&
        std::round(m_pos.getY() * 100) == std::round(m_PathToTravel[0].second * 100)) {
        m_PathToTravel.erase(m_PathToTravel.begin());
    }
}
