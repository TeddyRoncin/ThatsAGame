#include "pch.h"

#include "entity/RenderableEntity.h"

RenderableEntity::RenderableEntity(const char* path, Layer priority, Position<float> position, Dimension<float> size)
	:Entity(position.getX(), position.getY()), Renderable(path, &m_Position, &m_Size, priority), m_Size(size), m_RenderPriorityLevel(priority)
{
}

RenderableEntity::~RenderableEntity()
{
}

Layer RenderableEntity::GetRenderPriorityLevel() const
{
	return m_RenderPriorityLevel;
}
