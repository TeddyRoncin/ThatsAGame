#pragma once

#include "entity//Entity.h"
#include "test_folder/renderer/Layer.h"
#include "test_folder/renderer/Renderable.h"

class RenderableEntity: public Entity, public Renderable
{
public:
	RenderableEntity(const char* path, Position<float> position = {0, 0}, Dimension<float> dimension = {0, 0}, Layer priority = Layer::Ground);
	Layer GetRenderPriorityLevel() const;
	virtual Texture& GetTexture();

private:
	Layer m_RenderPriorityLevel;
};
