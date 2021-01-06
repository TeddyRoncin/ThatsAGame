#include "pch.h"

#include "entity//ai/Node.h"

Node::Node(const Position<float>& _position, const Position<float>& end, float step)
    : position(_position), comeFrom(nullptr)
{
    computeFCost(end, step);
}

Node::Node(const Position<float>& _position, const Node* _comeFrom, const Position<float>& end, float step) :
    comeFrom(_comeFrom),
    position(_position)
{
    computeFCost(end, step);
}

Node::Node(const Node& node) :
    comeFrom(node.comeFrom),
    gCost(node.gCost),
    fCost(node.fCost),
    position(node.position)
{
}

Node::~Node()
{
}

/*Node Node::operator=(const Node& node)
{
    comeFrom = node.comeFrom;
    gCost = node.gCost;
    fCost = node.fCost;
    position = node.position;
    return *this;
}*/

void Node::computeFCost(const Position<float>& end, float step)
{
    if (comeFrom == nullptr) {
        gCost = 0;
        fCost = 0;
        return;
    }
    gCost = comeFrom->gCost + position.DistanceFrom(comeFrom->position);
    fCost = gCost + std::abs(position.getX() - end.getX()) + std::abs(position.getY() - end.getY());
}