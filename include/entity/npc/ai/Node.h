#pragma once

#include "entity/Entity.h"

struct Node : public Entity
{
public:
    Node* m_ComeFrom;
    int m_GCost;
    int m_FCost;

public:
    Node(int posX, int posY, Node& comeFrom, int startX, int startY, int endX, int endY);
    Node(int posX, int posY, int startX, int startY, int endX, int endY);
    Node(int posX, int posY, Node* comeFrom, int startX, int startY, int endX, int endY);
    Node(const Node& node);

private:
    void computeFCost(int startX, int startY, int endX, int endY);

};