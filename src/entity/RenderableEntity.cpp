#include "pch.h"

#include "entity/RenderableEntity.h"

RenderableEntity::RenderableEntity(const char* path, Position<float> position, Dimension<float> size, Layer priority)
	:Entity(position.getX(), position.getY()), Renderable(path, &m_Position, &m_Size), m_Size(size), m_RenderPriorityLevel(priority)
{
}

Layer RenderableEntity::GetRenderPriorityLevel() const
{
	return m_RenderPriorityLevel;
}
