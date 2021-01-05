#include "pch.h"

#include "test_folder/entity/ai/PathFinder.h"

PathFinder::PathFinder(const Map& map) :
    m_Map(map), m_OpEnNoDeS(), m_ClosedNodes(), m_CurrentNode(nullptr), m_Step(0), m_End(0, 0), m_Entity(nullptr)
{
}

PathFinder::~PathFinder()
{}

std::vector<Position<float>> PathFinder::find(const Entity* entity, Position<float> end, int precision)
{
    // std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "\n";
    m_OpEnNoDeS.clear();
    m_ClosedNodes.clear();
    m_Entity = entity;
    m_Step = std::max<float>(m_Map.Width(), m_Map.Height()) / precision;
    m_End = end;
    m_ClosedNodes.reserve(precision * precision);
    m_OpEnNoDeS.reserve(precision * precision);
    Node firstNode(m_Entity->GetPosition(), m_End, m_Step);
    m_OpEnNoDeS.emplace_back(&firstNode);
    while (m_OpEnNoDeS.size() > 0) {
        int currentNodeId = findCurrentNode();
        m_OpEnNoDeS.erase(m_OpEnNoDeS.begin() + currentNodeId);
        m_ClosedNodes.emplace_back(m_CurrentNode);
        if (std::abs(m_CurrentNode->position.getX() - m_End.getX()) < m_Step / 2 && std::abs(m_CurrentNode->position.getY() - m_End.getY()) < m_Step / 2) {
            auto path = getPath();
            DestroyPointers();
            std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "\n";
            return path;
        }
        std::vector<Node*> newNeighbourNodes;
        getNeighbourNodes(newNeighbourNodes);
        for (Node* newNeighbourNode : newNeighbourNodes) {
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
                    }
                }
            }
        }
    }
    std::cout << "mission failed !\n";
    DestroyPointers();
    return std::vector<Position<float>>();
}

int PathFinder::findCurrentNode()
{
    m_CurrentNode = m_OpEnNoDeS[0];
    int currentNodeIndex = 0;
    for (int i = 1; i < m_OpEnNoDeS.size(); i++) {
        if (m_CurrentNode->fCost == 0 || m_OpEnNoDeS[i]->fCost < m_CurrentNode->fCost) {
            m_CurrentNode = m_OpEnNoDeS[i];
            currentNodeIndex = i;
        }
    }
    return currentNodeIndex;
}

void PathFinder::getNeighbourNodes(std::vector<Node*>& neighbourNodesDest)
{
    std::vector<Position<float>> neighbourNodeCoords {
        { m_CurrentNode->position.getX(), m_CurrentNode->position.getY() - m_Step },
        { m_CurrentNode->position.getX() + m_Step, m_CurrentNode->position.getY() },
        { m_CurrentNode->position.getX(), m_CurrentNode->position.getY() + m_Step },
        { m_CurrentNode->position.getX() - m_Step, m_CurrentNode->position.getY() },
        { m_CurrentNode->position.getX() - m_Step, m_CurrentNode->position.getY() - m_Step },
        { m_CurrentNode->position.getX() - m_Step, m_CurrentNode->position.getY() + m_Step },
        { m_CurrentNode->position.getX() + m_Step, m_CurrentNode->position.getY() - m_Step },
        { m_CurrentNode->position.getX() + m_Step, m_CurrentNode->position.getY() + m_Step },
    };
    for (Position<float> node : neighbourNodeCoords) {
        if((abs(node.getX()) + abs(node.getY()) * m_Map.Width()) > (m_Map.Width() * m_Map.Height())) {
            std::cout << "cuicui\n";
        }
        Entity& otherEntity = *m_Map[abs(node.getX()) + abs(node.getY()) * m_Map.Width()];
        if (node.getX() >= -m_Step / 2 && abs(node.getX() - m_Map.Width()) > m_Step / 2 &&
                node.getY() >= -m_Step / 2 && abs(node.getY() - m_Map.Height()) > m_Step / 2 &&
                otherEntity(*m_Entity) &&
                !containsNode(m_ClosedNodes, node)) {
            neighbourNodesDest.push_back(new Node(node, m_ClosedNodes[m_ClosedNodes.size() - 1], m_End, m_Step));
        }
    }
}

bool PathFinder::containsNode(const std::vector<Node*>& vector, const Node& nodeToSearch) const
{
    for (Node* node : vector) {
        if (std::abs(node->position.getX() - nodeToSearch.position.getX()) < m_Step / 2 && std::abs(node->position.getY() - nodeToSearch.position.getY()) < m_Step / 2) {
            return true;
        }
    }
    return false;
}

bool PathFinder::containsNode(const std::vector<const Node*>& vector, const Position<float>& coords) const
{
    for (const Node* node : vector) {
        if (std::abs(node->position.getX() - coords.getX()) < m_Step / 2 && std::abs(node->position.getY() - coords.getY()) < m_Step / 2) {
            return true;
        }
    }
    return false;
}

void PathFinder::DestroyPointers()
{
    for (int i(0); i < m_OpEnNoDeS.size(); i++) {
        if (m_OpEnNoDeS[i]) {
            delete m_OpEnNoDeS[i];
            m_OpEnNoDeS[i] = nullptr;
        }
    }
    for (int i(1); i < m_ClosedNodes.size(); i++) {  // The first one is not a dynamic allocation
        if (m_ClosedNodes[i]) {
            delete m_ClosedNodes[i];
            m_ClosedNodes[i] = nullptr;
        }
    }
}

std::vector<Position<float>> PathFinder::getPath()
{
    std::vector<Position<float>> path;
    while (m_CurrentNode->comeFrom) {
        path.push_back({ m_CurrentNode->position.getX(), m_CurrentNode->position.getY() });
        m_CurrentNode = m_CurrentNode->comeFrom;
    }
    path.push_back({ m_CurrentNode->position.getX(), m_CurrentNode->position.getY() });
    std::reverse(path.begin(), path.end());
    return path;
}