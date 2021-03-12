#pragma once

#include "entity/RenderableEntity.h"
#include "entity/TestAnimable.h"

class MovableEntity : public AnimableEntity
{
public:
	MovableEntity(const char* path, const SpriteSheetInfo& info, Position<float> position = {0.0f, 0.0f}, Dimension<float> dimension = {1.0f, 1.0f});
	virtual ~MovableEntity() override;
};
