#include "pch.h"

#include "test_folder/entity/ai/PathFinder.h"

PathFinder::PathFinder(const Map& map) :
    m_Map(map), m_OpEnNoDeS(), m_ClosedNodes(), m_CurrentNode({0, 0}, {0, 0}, 0), m_Step(0), m_End(0, 0), m_Entity(nullptr)
{
}

PathFinder::~PathFinder()
{}

std::vector<Position<float>> PathFinder::find(const Entity* entity, Position<float> end, int precision)
{
    //m_OpEnNoDeS.clear();
    //m_ClosedNodes.clear();
    m_Entity = entity;
    m_Step = std::max(m_Map.Width(), m_Map.Height()) / (float) precision;
    m_End = end;
    m_ClosedNodes.reserve(precision * precision);
    m_OpEnNoDeS.reserve(precision * precision);
    Node firstNode(m_Entity->GetPosition(), m_End, m_Step);
    m_OpEnNoDeS.emplace_back(&firstNode);
    while (m_OpEnNoDeS.size() > 0) {
        int currentNodeId = findCurrentNode();
        /*std::cout << "----" << std::endl;
        std::cout << currentNode.position.getX() << "   " << currentNode.position.getY() << std::endl;
        std::cout << m_OpEnNoDeS.size() << std::endl;*/
        m_OpEnNoDeS.erase(m_OpEnNoDeS.begin() + currentNodeId);
        std::cout << m_OpEnNoDeS.size() << std::endl;
        m_ClosedNodes.emplace_back(&m_CurrentNode);
        if (std::abs(m_CurrentNode.position.getX() - m_End.getX()) < m_Step / 2 && std::abs(m_CurrentNode.position.getY() - m_End.getY()) < m_Step / 2) {
            std::cout << "on a trouve !" << std::endl;
            //std::cout << m_CurrentNode.position.getX() << "   " << currentNode.position.getY() << std::endl;
            auto path = getPath();
            std::cout << "on a get le path !" << std::endl;
            DestroyPointers();
            std::cout << "les ptrs sont detruits !" << std::endl;
            return path;
        }
        std::vector<Node*> newNeighbourNodes;
        getNeighbourNodes(newNeighbourNodes);
        for (Node* newNeighbourNode : newNeighbourNodes) {
            //std::cout << newNeighbourNode.position.getX() << "    " << newNeighbourNode.position.getY() << std::endl;
            if (!containsNode(m_OpEnNoDeS, *newNeighbourNode)) {
                m_OpEnNoDeS.emplace_back(newNeighbourNode);
            } else {
                for (Node* node : m_OpEnNoDeS) {
                    if (std::abs(newNeighbourNode->position.getX() - node->position.getX()) < m_Step / 2
                            && std::abs(newNeighbourNode->position.getY() - node->position.getY()) < m_Step / 2
                            && newNeighbourNode->fCost < node->fCost) {
                        node->comeFrom = newNeighbourNode->comeFrom;
                        node->gCost = newNeighbourNode->gCost;
                        node->fCost = newNeighbourNode->fCost;
                        if (node->comeFrom == node)
                        {
                            std::cout << "wtf ??" << std::endl;
                        }
                    }
                }
            }
        }
    }
    DestroyPointers();
    return std::vector<Position<float>>();
}

int PathFinder::findCurrentNode()
{
    m_CurrentNode = *m_OpEnNoDeS[0];
    int currentNodeIndex = 0;
    for (int i = 1; i < m_OpEnNoDeS.size(); i++) {
        if (m_CurrentNode.fCost == 0 || m_OpEnNoDeS[i]->fCost < m_CurrentNode.fCost) {
            m_CurrentNode = *m_OpEnNoDeS[i];
            currentNodeIndex = i;
        }
    }
    return currentNodeIndex;
}

void PathFinder::getNeighbourNodes(std::vector<Node*>& neighbourNodesDest)
{
    std::vector<Position<float>> neighbourNodeCoords {
        { m_CurrentNode.position.getX(), m_CurrentNode.position.getY() - m_Step },
        { m_CurrentNode.position.getX() + m_Step, m_CurrentNode.position.getY() },
        { m_CurrentNode.position.getX(), m_CurrentNode.position.getY() + m_Step },
        { m_CurrentNode.position.getX() - m_Step, m_CurrentNode.position.getY() }
    };
    for (Position<float> node : neighbourNodeCoords) {
        if (node.getX() >= -m_Step / 2 && abs(node.getX() - m_Map.Width()) > m_Step / 2 &&
                node.getY() >= -m_Step / 2 && abs(node.getY() - m_Map.Height()) > m_Step / 2 &&
                !m_Map.DoesStaticCollide(m_Entity) &&
                !containsNode(m_ClosedNodes, node)) {
            neighbourNodesDest.push_back(new Node(node, m_ClosedNodes[m_ClosedNodes.size() - 1], m_End, m_Step));
        }
    }
}

bool PathFinder::containsNode(const std::vector<Node*>& vector, const Node& nodeToSearch) const
{
    return containsNode(vector, nodeToSearch.position);
}

bool PathFinder::containsNode(const std::vector<Node*>& vector, const Position<float>& coords) const
{
    for (Node* node : vector) {
        if (std::abs(node->position.getX() - coords.getX()) < m_Step / 2 && std::abs(node->position.getY() - coords.getY()) < m_Step / 2) {
            return true;
        }
    }
    return false;
}

void PathFinder::DestroyPointers()
{
    //m_OpEnNoDeS.clear();
    //m_ClosedNodes.clear();
    for (int i(0); i < m_OpEnNoDeS.size(); i++) {
        delete m_OpEnNoDeS[i];
    }
    for (int i(0); i < m_ClosedNodes.size(); i++) {
        delete m_ClosedNodes[i];
    }
}

std::vector<Position<float>> PathFinder::getPath()
{
    std::vector<Position<float>> path;
    while (m_CurrentNode.comeFrom) {
        path.push_back({ m_CurrentNode.position.getX(), m_CurrentNode.position.getY() });
        m_CurrentNode = *m_CurrentNode.comeFrom;
    }
    path.push_back({ m_CurrentNode.position.getX(), m_CurrentNode.position.getY() });
    std::reverse(path.begin(), path.end());
    return path;
}