#include "pch.h"

#include "entity/npc/SimpleNpc.h"
#include "entity/Entity.h"

SimpleNpc::SimpleNpc(int x, int y) :
    Npc("salut", x, y, 0.5, 0.5, "assets/textures/test.png")
{
}

void SimpleNpc::addPathFinder(const PathFinder& pathFinder) {
    m_PathToTravel = pathFinder.find(std::floor(m_pos.getX()), std::floor(m_pos.getY()), 2, 2, this);
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
    if (std::round(m_pos.getX() * 100) == std::round(m_PathToTravel[0].first * 100) &&
        std::round(m_pos.getY() * 100) == std::round(m_PathToTravel[0].second * 100)) {
        m_PathToTravel.erase(m_PathToTravel.begin());
    }
}
