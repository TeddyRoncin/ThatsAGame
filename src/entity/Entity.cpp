#include "entity/Entity.h"

std::pair<float, float> Entity::getPosition()
{
    return m_Position;
}

float Entity::getX()
{
    return m_Position.first;
}

float Entity::getY()
{
    return m_Position.second;
}