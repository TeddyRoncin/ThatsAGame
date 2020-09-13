#pragma once

#include "entity/npc/ai/Node.h"
#include "map/Map.h"

class PathFinder
{

public:
    PathFinder(Map& map);
    std::vector<std::pair<int, int>> find(int startX, int startY, int endX, int endY, Entity* entity);

private:
    Map& m_Map;

private:
    int findCurrentNode(std::vector<Node> openNodes);
    std::vector<Node> getNeighbourNodes(Node currentNode, int startX, int startY, int endX, int endY, Entity* entity, std::vector<Node>& closedNodes);
    bool containsNode(std::vector<Node> vector, Node nodeToSearch);
    bool containsNode(std::vector<Node> vector, std::pair<int, int> coords);
    std::vector<std::pair<int, int>> getPath(int startX, int startY, Node currentNode);

};