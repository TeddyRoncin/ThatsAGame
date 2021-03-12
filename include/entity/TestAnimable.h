#pragma once

#include "entity/Entity.h"
#include "renderer/Animable.h"

class AnimableEntity : public Entity, public Animable
{
public:
	AnimableEntity(const char* path, Layer priority, const SpriteSheetInfo& info, Position<float> position = {0, 0}, Dimension<float> dimension = {0, 0});
	virtual ~AnimableEntity() override;
	Layer GetRenderPriorityLevel() const;

	void Tick(float dt = 0.0f) override;

	Dimension<float> GetSize() const;
private:
	Dimension<float> m_Size;
	Layer m_RenderPriorityLevel;
};
