#include "pch.h"

#include "entity/npc/ai/Node.h"

Node::Node(int posX, int posY, Node comeFrom, int startX, int startY, int endX, int endY) :
Entity(posX, posY),
m_ComeFrom(&comeFrom)
{
    //std::cout << "le come from ds le constructeur ! (sans ptr) : " << m_ComeFrom << std::endl;
    computeFCost(startX, startY, endX, endY);
}

Node::Node(int posX, int posY, Node* comeFrom, int startX, int startY, int endX, int endY) :
Entity(posX, posY),
m_ComeFrom(comeFrom)
{
    //std::cout << "le come from ds le constructeur ! (avc ptr) : " << m_ComeFrom << std::endl;
    computeFCost(startX, startY, endX, endY);
}

Node::Node(const Node& node) :
Entity(node.getX(), node.getY()),
m_ComeFrom(node.m_ComeFrom),
m_GCost(node.m_GCost),
m_FCost(node.m_FCost)
{
}

void Node::computeFCost(int startX, int startY, int endX, int endY)
{
    //std::cout << "le comeFrom : " << m_ComeFrom << std::endl;
    if (m_ComeFrom == nullptr) {
        m_GCost = 0;
        m_FCost = 0;
        return;
    }
    m_GCost = m_ComeFrom->m_GCost + 1;
    m_FCost = m_GCost + std::abs(std::round(getX()) - endX) + std::abs(std::round(getY()) - endY);
}