#pragma once

#include "entity/MovableEntity.h"

class MovableElement : public MovableEntity
{
public:
	MovableElement(const char* path, Position<float> position, Dimension<float> dimension);
	virtual ~MovableElement();
};
