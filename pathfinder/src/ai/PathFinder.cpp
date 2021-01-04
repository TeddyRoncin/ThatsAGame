#include "pch.h"

#include "test_folder/entity/ai/PathFinder.h"

PathFinder::PathFinder(const Map& map) :
    m_Map(map)
{
}

PathFinder::~PathFinder()
{}

std::vector<Position<float>> PathFinder::find(const Position<float>& start, const Position<float>& end, const Entity* entity, int precision) const
{
    float step = std::max(m_Map.Width(), m_Map.Height()) / (float) precision;
    std::vector<Node> openNodes;
    std::vector<Node> closedNodes;
    closedNodes.reserve(precision * precision);
    Node firstNode(start, end, step);
    openNodes.push_back(firstNode);
    while (openNodes.size() > 0) {
        auto[currentNodeId, currentNode] = findCurrentNode(openNodes, step);
        /*std::cout << "----" << std::endl;
        std::cout << currentNode.position.getX() << "   " << currentNode.position.getY() << std::endl;
        std::cout << openNodes.size() << std::endl;*/
        openNodes.erase(openNodes.begin() + currentNodeId);
        //std::cout << openNodes.size() << std::endl;
        closedNodes.push_back(currentNode);
        if (std::abs(currentNode.position.getX() - end.getX()) < step / 2 && std::abs(currentNode.position.getY() - end.getY()) < step / 2) {
            std::cout << currentNode.position.getX() << "   " << currentNode.position.getY() << std::endl;
            return getPath(start, currentNode);
        }
        std::vector<Node> newNeighbourNodes = getNeighbourNodes(currentNode, start, entity, closedNodes, step);
        for (Node newNeighbourNode : newNeighbourNodes) {
            std::cout << newNeighbourNode.position.getX() << "    " << newNeighbourNode.position.getY() << std::endl;
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

std::pair<int, Node> PathFinder::findCurrentNode(const std::vector<Node>& openNodes, float step) const
{
    const Node* currentNode = &openNodes[0];//({0, 0}, {0, 0}, 0);
    int currentNodeIndex = 0;
    for (int i = 1; i < openNodes.size(); i++) {
        if (currentNode->fCost == 0 || openNodes[i].fCost < currentNode->fCost) {
            currentNode = &openNodes[i];
            currentNodeIndex = i;
        }
    }
    return {currentNodeIndex, *currentNode};
}

std::vector<Node> PathFinder::getNeighbourNodes(const Node& currentNode, const Position<float>& end, const Entity* const entity, const std::vector<Node>& closedNodes, float step) const
{
    std::vector<Node> neighbourNodes;
    std::vector<Position<float>> neighbourNodeCoords {
        { currentNode.position.getX(), currentNode.position.getY() - step },
        { currentNode.position.getX() + step, currentNode.position.getY() },
        { currentNode.position.getX(), currentNode.position.getY() + step },
        { currentNode.position.getX() - step, currentNode.position.getY() }
    };
    for (Position<float> node : neighbourNodeCoords) {
        if (node.getX() >= -step / 2 && abs(node.getX() - m_Map.Width()) > step / 2 &&
                node.getY() >= -step / 2 && abs(node.getY() - m_Map.Height()) > step / 2 &&
                !m_Map.DoesStaticCollide(entity) &&
                !containsNode(closedNodes, node, step)) {
            neighbourNodes.push_back(Node(node, closedNodes[closedNodes.size() - 1], end, step));
        }
    }
    return neighbourNodes;
}

bool PathFinder::containsNode(const std::vector<Node>& vector, const Node& nodeToSearch, float step) const
{
    return containsNode(vector, nodeToSearch.position, step);
}

bool PathFinder::containsNode(const std::vector<Node>& vector, const Position<float>& coords, float step) const
{
    for (Node node : vector) {
        if (std::abs(node.position.getX() - coords.getX()) < step / 2 && std::abs(node.position.getY() - coords.getY()) < step / 2) {
            return true;
        }
    }
    return false;
}

std::vector<Position<float>> PathFinder::getPath(const Position<float>& start, const Node& node) const
{
    const Node* currentNode = &node;
    std::vector<Position<float>> path;
    while (currentNode->comeFrom) {
        path.push_back({ currentNode->position.getX(), currentNode->position.getY() });
        currentNode = currentNode->comeFrom;
    }
    path.push_back({ currentNode->position.getX(), currentNode->position.getY() });
    std::reverse(path.begin(), path.end());
    return path;
}