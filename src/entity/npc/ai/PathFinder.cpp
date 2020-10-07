#include "pch.h"

#include "entity/npc/ai/PathFinder.h"

PathFinder::PathFinder(const Map& map) :
    m_Map(map)
{
}

PathFinder::~PathFinder()
{}

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
        if (std::round(currentNode.m_pos.getX()) == endX && std::round(currentNode.m_pos.getY()) == endY) {
            return getPath(startX, startY, currentNode);
        }
        std::vector<Node> newNeighbourNodes = getNeighbourNodes(currentNode, startX, startY, endX, endY, entity, closedNodes);
        for (Node newNeighbourNode : newNeighbourNodes) {
            if (!containsNode(openNodes, newNeighbourNode)) {
                openNodes.push_back(newNeighbourNode);
            } else {
                for (Node node : openNodes) {
                    if (std::round(newNeighbourNode.m_pos.getX()) == std::round(node.m_pos.getX()) &&
                    std::round(newNeighbourNode.m_pos.getY()) == std::round(node.m_pos.getY())
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
        std::pair<int, int>(std::round(currentNode.m_pos.getX()), std::round(currentNode.m_pos.getY() - 1)),
        std::pair<int, int>(std::round(currentNode.m_pos.getX() + 1), std::round(currentNode.m_pos.getY())),
        std::pair<int, int>(std::round(currentNode.m_pos.getX()), std::round(currentNode.m_pos.getY() + 1)),
        std::pair<int, int>(std::round(currentNode.m_pos.getX() - 1), std::round(currentNode.m_pos.getY()))
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
    return containsNode(vector, std::pair<int, int>(std::round(nodeToSearch.m_pos.getX()), std::round(nodeToSearch.m_pos.getY())));
}

bool PathFinder::containsNode(std::vector<Node> vector, std::pair<int, int> coords)
{
    for (Node node : vector) {
        if (std::round(node.m_pos.getX()) == coords.first && std::round(node.m_pos.getY()) == coords.second) {
            return true;
        }
    }
    return false;
}

std::vector<std::pair<int, int>> PathFinder::getPath(int startX, int startY, Node currentNode)
{
    std::vector<std::pair<int, int>> path;
    while (std::round(currentNode.m_pos.getX()) != startX || std::round(currentNode.m_pos.getY()) != startY) {
        path.push_back(std::pair<int, int>(std::round(currentNode.m_pos.getX()), std::round(currentNode.m_pos.getY())));
        // std::cout << currentNode.m_ComeFrom << std::endl;
        currentNode = *currentNode.m_ComeFrom;
    }
    path.push_back(std::pair<int, int>(std::round(currentNode.m_pos.getX()), std::round(currentNode.m_pos.getY())));
    std::reverse(path.begin(), path.end());
    return path;
}