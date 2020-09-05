#include "pch.h"

#include "entity/Entity.h"

Entity::Entity(float x, float y) :
m_Position(std::pair<float, float>(x, y))
{

}

Entity::Entity(const Entity& entity) :
m_Position(std::pair<float, float>(entity.m_Position.first, entity.m_Position.second))
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