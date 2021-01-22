#pragma once

#include "entity/Entity.h"
#include "renderer/Layer.h"
#include "renderer/Renderable.h"

class RenderableEntity: public Entity, public Renderable
{
public:
	RenderableEntity(const char* path, Position<float> position = {0, 0}, Dimension<float> dimension = {0, 0}, Layer priority = Layer::Ground);
	Layer GetRenderPriorityLevel() const;

private:
	Dimension<float> m_Size;
	Layer m_RenderPriorityLevel;
};
