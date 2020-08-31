#include <math.h>

#include "entity/npc/ai/PathFinder.h"

PathFinder::PathFinder(Map map) :
m_Map(map)
{

}

std::vector<std::pair<int, int>> PathFinder::find(int startX, int startY, int endX, int endY, Entity* entity)
{
    std::vector<Node> openNodes;
    std::vector<Node> closedNodes;
    openNodes.push_back(Node(startX, startY, nullptr, 0, 0, 0, 0));
    while (true) {
        int currentNodeId = findCurrentNode(openNodes);
        Node currentNode = openNodes[currentNodeId];
        //std::cout << currentNode.getX() << currentNode.getY() << std::endl;
        openNodes.erase(openNodes.begin() + currentNodeId);
        closedNodes.push_back(currentNode);
        if (currentNode.getX() == endX && currentNode.getY() == endY) {
            return getPath(startX, startY, currentNode);
        }
        std::vector<Node> newNeighbourNodes = getNeighbourNodes(currentNode, startX, startY, endX, endY, m_Map, entity, closedNodes);
        for (Node newNeighbourNode : newNeighbourNodes) {
            if (!containsNode(openNodes, newNeighbourNode)) {
                openNodes.push_back(newNeighbourNode);
            } else {
                for (Node node : openNodes) {
                    if (node.getPosition() == newNeighbourNode.getPosition() && newNeighbourNode.m_FCost < node.m_FCost) {
                        node.m_ComeFrom = newNeighbourNode.m_ComeFrom;
                        node.m_FCost = newNeighbourNode.m_FCost;
                    }
                }
            }
        }
    }
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

std::vector<Node> PathFinder::getNeighbourNodes(Node currentNode, int startX, int startY, int endX, int endY, Map map, Entity* entity, std::vector<Node> closedNodes)
{
    std::vector<Node> neighbourNodes;
    std::vector<std::pair<int, int>> neighbourNodeCoords {
        std::pair<int, int>(std::round(currentNode.getX()), std::round(currentNode.getY() - 1)),
        std::pair<int, int>(std::round(currentNode.getX() + 1), std::round(currentNode.getY())),
        std::pair<int, int>(std::round(currentNode.getX()), std::round(currentNode.getY() + 1)),
        std::pair<int, int>(std::round(currentNode.getX() - 1), std::round(currentNode.getY()))
    };
    for (std::pair<int, int> coords : neighbourNodeCoords) {
        if (coords.first >= 0 && coords.first < map.getWidth() &&
        coords.second >= 0 && coords.second < map.getHeight() &&
        map.canEntityMoveAt(coords.first, coords.second, entity) &&
        !containsNode(closedNodes, coords)) {
            Node node = Node(coords.first, coords.second, currentNode, startX, startY, endX, endY);
            neighbourNodes.push_back(Node(coords.first, coords.second, currentNode, startX, startY, endX, endY));
        }
    }
    return neighbourNodes;
}

bool PathFinder::containsNode(std::vector<Node> vector, Node nodeToSearch)
{
    return containsNode(vector, nodeToSearch.getPosition());
}

bool PathFinder::containsNode(std::vector<Node> vector, std::pair<int, int> coords)
{
    for (Node node : vector) {
        if (node.getX() == coords.first && node.getY() == coords.second) {
            return true;
        }
    }
    return false;
}

std::vector<std::pair<int, int>> PathFinder::getPath(int startX, int startY, Node currentNode)
{
    std::vector<std::pair<int, int>> path;
    while (currentNode.getX() != startX && currentNode.getY() != startY) {
        //std::cout << "Il y a qq chose !" << std::endl;
        path.push_back(std::pair<int, int>(currentNode.getX(), currentNode.getY()));
        currentNode = *currentNode.m_ComeFrom;
    }
    path.push_back(std::pair<int, int>(currentNode.getX(), currentNode.getY()));
    return path;
}