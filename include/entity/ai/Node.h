#pragma once

struct Node
{
public:
	const Node* comeFrom;
	float gCost;
	float fCost;
	Position<float> position;

public:
	Node(const Position<float>& _position, const Position<float>& end, float step);
	Node(const Position<float>& _position, const Node* _comeFrom, const Position<float>& end, float step);
	Node(const Node& node);
	~Node();

private:
	void computeFCost(const Position<float>& end, float step);
};
