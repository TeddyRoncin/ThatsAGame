#include "pch.h"

#include "test_folder/entity/ai/Node.h"

Node::Node(Position<float> _position, Position<float> end, float step)
    : position(position), comeFrom(nullptr)
{
    computeFCost(end);
}

Node::Node(Position<float> _position, Node& _comeFrom, Position<float> end, float step) :
    comeFrom(&_comeFrom),
    position(_position)
{
    computeFCost(end, step);
}

Node::Node(Position<float> _position, Node* _comeFrom, Position<float> end, float step) :
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

void Node::computeFCost(Position<float> end, float step)
{
    if (comeFrom == nullptr) {
        gCost = 0;
        fCost = 0;
        return;
    }
    gCost = comeFrom->gCost + step;
    fCost = gCost + std::abs(position.getX() - end.getX()) + std::abs(position.getY() - end.getY());
}