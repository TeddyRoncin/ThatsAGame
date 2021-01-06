#include "pch.h"

#include "entity//RenderableEntity.h"

RenderableEntity::RenderableEntity(const char* path, Position<float> position, Dimension<float> size, Layer priority)
	:Entity(position.getX(), position.getY()), Renderable(path, position, size), m_RenderPriorityLevel(priority)
{
}

Layer RenderableEntity::GetRenderPriorityLevel() const
{
	return m_RenderPriorityLevel;
}

Texture& RenderableEntity::GetTexture()
{
	m_Texture.position = GetPosition();
	m_Texture.size = {1, 1};
	return m_Texture;
}
