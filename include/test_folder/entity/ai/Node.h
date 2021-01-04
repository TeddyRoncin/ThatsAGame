#pragma once

struct Node
{
public:
    Node* comeFrom;
    float gCost;
    float fCost;
    Position<float> position;

public:
    Node(Position<float> _position, Position<float> end, float step);
    Node(Position<float> _position, Node& _comeFrom, Position<float> end, float step);
    Node(Position<float> _position, Node* _comeFrom, Position<float> end, float step);
    Node(const Node& node);

private:
    void computeFCost(Position<float> end, float step);
};
