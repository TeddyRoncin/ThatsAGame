#include "pch.h"

#include "entity/Renderable.h"

Renderable::Renderable(const char* name, float x, float y, float width, float height, const char* sprite)
	:Entity(name, x, y), m_dim(width,height), m_sprite(sprite)
{
}

Renderable::~Renderable()
{
}
