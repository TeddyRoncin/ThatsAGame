#pragma once

#include "entity/Entity.h"
#include "renderer/Layer.h"
#include "renderer/Renderable.h"

class RenderableEntity: public Entity, public Renderable
{
public:
	RenderableEntity(const char* path, Layer priority, Position<float> position = {0.0f, 0.0f}, Dimension<float> dimension = {1.0f, 1.0f});
	virtual ~RenderableEntity() override;
	Layer GetRenderPriorityLevel() const;

	Dimension<float> GetSize() const;

private:
	Dimension<float> m_Size;
	Layer m_RenderPriorityLevel;
};
