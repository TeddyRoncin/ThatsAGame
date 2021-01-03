#include "pch.h"

#include "test_folder/entity/RenderableEntity.h"

RenderableEntity::RenderableEntity(char* path, Position<float> position, Dimension<float> size)
	:Entity(position.getX(), position.getY()), Renderable(path, position, size)
{
}
