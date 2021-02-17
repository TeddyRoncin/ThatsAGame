#pragma once

#include "entity//ai/Node.h"
#include "map/Map.h"

class PathFinder
{

public:
	PathFinder(const Map& map);
	~PathFinder();
	std::vector<Position<float>> find(const Entity* const entity, Position<float> end, int precision);

private:
	const Map& m_Map;
	std::vector<Node*> m_OpEnNoDeS;
	std::vector<const Node*> m_ClosedNodes;
	const Node* m_CurrentNode;
	float m_Step;
	Position<float> m_End;
	const Entity* m_Entity;

private:
	int findCurrentNode();
	void getNeighbourNodes(std::vector<Node*>& neighbourNodesDest);
	bool containsNode(const std::vector<const Node*>& vector, const Position<float>& coords) const;
	bool containsNode(const std::vector<Node*>& vector, const Node& nodeToSearch) const;
	void DestroyPointers();
	std::vector<Position<float>> getPath();

};
