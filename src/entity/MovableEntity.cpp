#include "pch.h"

#include "entity/MovableEntity.h"
#include "renderer/Layer.h"

MovableEntity::MovableEntity(const char* path, const SpriteSheetInfo& info, Position<float> position, Dimension<float> dimension)
	: AnimableEntity(path, Layer::MovableElements, info, position, dimension)
{
}

MovableEntity::~MovableEntity()
{
}
