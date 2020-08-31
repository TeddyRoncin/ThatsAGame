#include "entity/Entity.h"

Entity::Entity(float x, float y) :
m_Position(x, y)
{

}

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