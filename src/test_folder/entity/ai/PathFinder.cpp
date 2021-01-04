#include "pch.h"

#include "test_folder/entity/ai/PathFinder.h"

PathFinder::PathFinder(const Map& map) :
    m_Map(map)
{
}

PathFinder::~PathFinder()
{}

std::vector<Position<float>> PathFinder::find(Position<float> start, Position<float> end, Entity* entity, int precision) const
{
    float step = std::max(m_Map.Width(), m_Map.Height()) / precision;
    std::vector<Node> openNodes;
    std::vector<Node> closedNodes;
    closedNodes.reserve(precision * precision);
    Node firstNode(start, end, step);
    openNodes.push_back(firstNode);
    while (openNodes.size() > 0) {
        auto[currentNodeId, currentNode] = findCurrentNode(openNodes, step);
        openNodes.erase(openNodes.begin() + currentNodeId);
        closedNodes.push_back(currentNode);
        if (std::abs(currentNode.position.getX() - end.getX()) < step / 2 && std::abs(currentNode.position.getY() - end.getY()) < step / 2) {
            return getPath(start, currentNode);
        }
        std::vector<Node> newNeighbourNodes = getNeighbourNodes(currentNode, start, entity, closedNodes, step);
        for (Node newNeighbourNode : newNeighbourNodes) {
            if (!containsNode(openNodes, newNeighbourNode, step)) {
                openNodes.push_back(newNeighbourNode);
            } else {
                for (Node node : openNodes) {
                    if (std::abs(newNeighbourNode.position.getX() - node.position.getX()) < step / 2
                            && std::abs(newNeighbourNode.position.getY() - node.position.getY()) < step / 2
                            && newNeighbourNode.fCost < node.fCost) {
                        node.comeFrom = newNeighbourNode.comeFrom;
                        node.gCost = newNeighbourNode.gCost;
                        node.fCost = newNeighbourNode.fCost;
                    }
                }
            }
        }
    }
    return std::vector<Position<float>>();
}

std::pair<int, Node> PathFinder::findCurrentNode(std::vector<Node> openNodes, float step) const
{
    Node currentNode({0, 0}, {0, 0}, 0);
    int currentNodeIndex;
    for (int i = 0; i < openNodes.size(); i++) {
        if (currentNode.fCost == 0 || openNodes[i].fCost < currentNode.fCost) {
            currentNode = openNodes[i];
            currentNodeIndex = i;
        }
    }
    return {currentNodeIndex, currentNode};
}

std::vector<Node> PathFinder::getNeighbourNodes(Node currentNode, Position<float> end, Entity* entity, std::vector<Node>& closedNodes, float step) const
{
    std::vector<Node> neighbourNodes;
    std::vector<Position<float>> neighbourNodeCoords {
        { std::round(currentNode.position.getX()), std::round(currentNode.position.getY() - step) },
        { std::round(currentNode.position.getX() + step), std::round(currentNode.position.getY()) },
        { std::round(currentNode.position.getX()), std::round(currentNode.position.getY() + step) },
        { std::round(currentNode.position.getX() - step), std::round(currentNode.position.getY()) }
    };
    for (Position<float> node : neighbourNodeCoords) {
        if (abs(node.getX()) >= step / 2 && abs(node.getX() - m_Map.Width()) < step / 2 &&
                abs(node.getY()) >= step / 2 && abs(node.getY() - m_Map.Height()) < step / 2 &&
                m_Map.DoesStaticCollide(entity) &&
                !containsNode(closedNodes, node, step)) {
            neighbourNodes.push_back(Node(node, closedNodes[closedNodes.size() - 1], end, step));
        }
    }
    return neighbourNodes;
}

bool PathFinder::containsNode(std::vector<Node> vector, Node nodeToSearch, float step) const
{
    return containsNode(vector, nodeToSearch.position, step);
}

bool PathFinder::containsNode(std::vector<Node> vector, Position<float> coords, float step) const
{
    for (Node node : vector) {
        if (std::abs(node.position.getX() - coords.getX()) < step / 2 && std::abs(node.position.getY() - coords.getY()) < step / 2) {
            return true;
        }
    }
    return false;
}

std::vector<Position<float>> PathFinder::getPath(Position<float> start, Node currentNode) const
{
    std::vector<Position<float>> path;
    while (currentNode.comeFrom != nullptr) {
        path.push_back({ currentNode.position.getX(), currentNode.position.getY() });
        currentNode = *currentNode.comeFrom;
    }
    path.push_back({ currentNode.position.getX(), currentNode.position.getY() });
    std::reverse(path.begin(), path.end());
    return path;
}