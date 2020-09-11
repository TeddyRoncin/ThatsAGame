#include "pch.h"

#include "entity/Renderable.h"

Renderable::Renderable(float x, float y, float width, float height, const char* _sprite)
	:m_pos(x,y), m_dim(width,height), sprite(_sprite)
{
}

Renderable::~Renderable()
{
}
