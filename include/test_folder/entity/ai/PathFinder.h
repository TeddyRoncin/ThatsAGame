#pragma once

#include "test_folder/entity/ai/Node.h"
#include "map/Map.h"

class PathFinder
{

public:
    PathFinder(const Map& map);
    PathFinder(Map map)
    ~PathFinder();
    std::vector<Position<float>> find(Position<float> start, Position<float> end, Entity* entity, int precision) const;

private:
    const Map& m_Map;

private:
    std::pair<int, Node> findCurrentNode(std::vector<Node> openNodes, float step) const;
    std::vector<Node> getNeighbourNodes(Node currentNode, Position<float> end, Entity* entity, std::vector<Node>& closedNodes, float step) const;
    bool containsNode(std::vector<Node> vector, Position<float> coords, float step) const;
    bool containsNode(std::vector<Node> vector, Node nodeToSearch, float step) const;
    std::vector<Position<float>> getPath(Position<float> start, Node currentNode) const;

};
