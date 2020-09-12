#include "pch.h"

#include "entity/Entity.h"

Entity::Entity(const char* name, float x, float y)
	:m_name(name), m_pos(x,y)
{
}

Entity::~Entity()
{
}
