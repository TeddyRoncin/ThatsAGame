#pragma once

#include "entity//RenderableEntity.h"

class MovableEntity : public RenderableEntity
{
public:
	MovableEntity(const char* path, Position<float> position = {0, 0}, Dimension<float> dimension = {0, 0});
};