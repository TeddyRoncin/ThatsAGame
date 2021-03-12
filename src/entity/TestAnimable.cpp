#include "pch.h"
#include "entity/TestAnimable.h"

AnimableEntity::AnimableEntity(const char* path, Layer priority, const SpriteSheetInfo& info, Position<float> position, Dimension<float> dimension)
	:Entity(position.getX(), position.getY()), Animable(path, &m_Position, &m_Size, priority, info), m_Size(dimension), m_RenderPriorityLevel(priority)
{
}

AnimableEntity::~AnimableEntity()
{
}

Layer AnimableEntity::GetRenderPriorityLevel() const
{
	return m_RenderPriorityLevel;
}

Dimension<float> AnimableEntity::GetSize() const
{
	return m_Size;
}

void AnimableEntity::Tick(float dt)
{
	if(dt > 1.0f) {
		updateTexture();
	}
}
