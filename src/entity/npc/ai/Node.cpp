#include <math.h>

#include "entity/npc/ai/Node.h"

Node::Node(int posX, int posY, Node comeFrom, int startX, int startY, int endX, int endY) :
Entity(posX, posY),
m_ComeFrom(&comeFrom)
{
}

Node::Node(int posX, int posY, Node* comeFrom, int startX, int startY, int endX, int endY) :
Entity(posX, posY),
m_ComeFrom(comeFrom)
{
}

void Node::computeFCost(int startX, int startY, int endX, int endY)
{
    if (m_ComeFrom == nullptr) {
        return;
    }
    m_GCost = m_ComeFrom->m_GCost + 1;
    m_FCost = m_GCost + std::abs(std::round(getX()) - endX) + std::abs(std::round(getY()) - endY);
}