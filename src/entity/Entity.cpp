#include "pch.h"

#include "entity/Entity.h"

Entity::Entity(float x, float y) :
m_Position(x, y)
{

}

std::pair<float, float> Entity::getPosition() const
{
    return m_Position;
}

float Entity::getX() const
{
    return m_Position.first;
}

float Entity::getY() const
{
    return m_Position.second;
}