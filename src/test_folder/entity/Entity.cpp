#include "pch.h"

#include "test_folder/entity/Entity.h"
#include "test_folder/entity/EntityManager.h"

Entity::Entity(float _x, float _y)
    :m_ID(EntityManager::GetNewID(this)), m_Position(_x, _y)
{}

bool Entity::operator()(const Entity& e)
{
    return true;
}

int Entity::GetID() const
{
    return m_ID;
}

// EntityType Entity::GetType() const
// {
//     return type;
// }

float Entity::GetX() const
{
    return m_Position.getX();
}

float Entity::GetY() const
{
    return m_Position.getY();
}

Position<float> Entity::GetPosition() const
{
    return m_Position;
}
