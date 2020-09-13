#include "pch.h"

#include "entity/npc/ai/PathFinder.h"

PathFinder::PathFinder(Map& map) :
m_Map(map)
{

}

std::vector<std::pair<int, int>> PathFinder::find(int startX, int startY, int endX, int endY, Entity* entity)
{
    std::vector<Node> openNodes;
    std::vector<Node> closedNodes;
    closedNodes.reserve(m_Map.getWidth() * m_Map.getHeight());
    Node firstNode(startX, startY, nullptr, 0, 0, 0, 0);
    openNodes.push_back(firstNode);
    while (openNodes.size() > 0) {
        int currentNodeId = findCurrentNode(openNodes);
        Node currentNode = openNodes[currentNodeId];
        openNodes.erase(openNodes.begin() + currentNodeId);
        closedNodes.push_back(currentNode);
        if (std::round(currentNode.getX()) == endX && std::round(currentNode.getY()) == endY) {
            return getPath(startX, startY, currentNode);
        }
        std::vector<Node> newNeighbourNodes = getNeighbourNodes(currentNode, startX, startY, endX, endY, entity, closedNodes);
        for (Node newNeighbourNode : newNeighbourNodes) {
            if (!containsNode(openNodes, newNeighbourNode)) {
                openNodes.push_back(newNeighbourNode);
            } else {
                for (Node node : openNodes) {
                    if (std::round(newNeighbourNode.getX()) == std::round(node.getX()) &&
                    std::round(newNeighbourNode.getY()) == std::round(node.getY())
                    && newNeighbourNode.m_FCost < node.m_FCost) {
                        node.m_ComeFrom = newNeighbourNode.m_ComeFrom;
                        node.m_FCost = newNeighbourNode.m_FCost;
                    }
                }
            }
        }
    }
    return std::vector<std::pair<int, int>>();
}

int PathFinder::findCurrentNode(std::vector<Node> openNodes)
{
    Node currentNode(0, 0, nullptr, 0, 0, 0, 0);
    int currentNodeIndex;
    for (int i = 0; i < openNodes.size(); i++) {
        if (currentNode.m_FCost == 0 || openNodes[i].m_FCost < currentNode.m_FCost) {
            currentNode = openNodes[i];
            currentNodeIndex = i;
        }
    }
    return currentNodeIndex;
}

std::vector<Node> PathFinder::getNeighbourNodes(Node currentNode, int startX, int startY, int endX, int endY, Entity* entity, std::vector<Node>& closedNodes)
{
    std::vector<Node> neighbourNodes;
    std::vector<std::pair<int, int>> neighbourNodeCoords {
        std::pair<int, int>(std::round(currentNode.getX()), std::round(currentNode.getY() - 1)),
        std::pair<int, int>(std::round(currentNode.getX() + 1), std::round(currentNode.getY())),
        std::pair<int, int>(std::round(currentNode.getX()), std::round(currentNode.getY() + 1)),
        std::pair<int, int>(std::round(currentNode.getX() - 1), std::round(currentNode.getY()))
    };
    for (auto[x, y] : neighbourNodeCoords) {
        if (x >= 0 && x < m_Map.getWidth() &&
        y >= 0 && y < m_Map.getHeight() &&
        m_Map.canEntityMoveAt(x, y, entity) &&
        !containsNode(closedNodes, std::pair<int, int>(x, y))) {
            neighbourNodes.push_back(Node(x, y, closedNodes[closedNodes.size() - 1], startX, startY, endX, endY));
        }
    }
    return neighbourNodes;
}

bool PathFinder::containsNode(std::vector<Node> vector, Node nodeToSearch)
{
    return containsNode(vector, std::pair<int, int>(std::round(nodeToSearch.getX()), std::round(nodeToSearch.getY())));
}

bool PathFinder::containsNode(std::vector<Node> vector, std::pair<int, int> coords)
{
    for (Node node : vector) {
        if (std::round(node.getX()) == coords.first && std::round(node.getY()) == coords.second) {
            return true;
        }
    }
    return false;
}

std::vector<std::pair<int, int>> PathFinder::getPath(int startX, int startY, Node currentNode)
{
    std::vector<std::pair<int, int>> path;
    while (std::round(currentNode.getX()) != startX || std::round(currentNode.getY()) != startY) {
        path.push_back(std::pair<int, int>(std::round(currentNode.getX()), std::round(currentNode.getY())));
        std::cout << currentNode.m_ComeFrom << std::endl;
        currentNode = *currentNode.m_ComeFrom;
    }
    path.push_back(std::pair<int, int>(std::round(currentNode.getX()), std::round(currentNode.getY())));
    return path;
}