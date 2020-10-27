#pragma once

#include "entity/npc/ai/Node.h"
#include "map/Map.h"

class PathFinder
{

public:
    PathFinder(const Map& map);
    ~PathFinder();
    std::vector<std::pair<int, int>> find(int startX, int startY, int endX, int endY, Entity* entity) const;

private:
    const Map& m_Map;

private:
<<<<<<< HEAD
    int findCurrentNode(std::vector<Node> openNodes) const;
    std::vector<Node> getNeighbourNodes(Node currentNode, int startX, int startY, int endX, int endY, Entity* entity, std::vector<Node>& closedNodes) const;
    bool containsNode(std::vector<Node> vector, Node nodeToSearch) const;
    bool containsNode(std::vector<Node> vector, std::pair<int, int> coords) const;
    std::vector<std::pair<int, int>> getPath(int startX, int startY, Node currentNode) const;
=======
    int findCurrentNode(std::vector<Node> openNodes);
    std::vector<Node> getNeighbourNodes(Node currentNode, int startX, int startY, int endX, int endY, Entity* entity, std::vector<Node>& closedNodes);
    bool containsNode(std::vector<Node> vector, Node nodeToSearch);
    bool containsNode(std::vector<Node> vector, std::pair<int, int> coords);
    std::vector<std::pair<int, int>> getPath(int startX, int startY, Node currentNode);
>>>>>>> github/functionnal

};
