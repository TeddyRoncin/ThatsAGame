#pragma once

#include "test_folder/entity/ai/Node.h"
#include "map/Map.h"

class PathFinder
{

public:
    PathFinder(const Map& map);
    ~PathFinder();
    std::vector<Position<float>> find(const Position<float>& start, const Position<float>& end, const Entity* const entity, int precision) const;

private:
    const Map& m_Map;

private:
    std::pair<int, Node> findCurrentNode(const std::vector<Node>& openNodes, float step) const;
    std::vector<Node> getNeighbourNodes(const Node& currentNode, const Position<float>& end, const Entity* entity, const std::vector<Node>& closedNodes, float step) const;
    bool containsNode(const std::vector<Node>& vector, const Position<float>& coords, float step) const;
    bool containsNode(const std::vector<Node>& vector, const Node& nodeToSearch, float step) const;
    std::vector<Position<float>> getPath(const Position<float>& start, const Node& currentNode) const;

};
