#include "pch.h"

#include "entity//MovableEntity.h"
#include "renderer/Layer.h"

MovableEntity::MovableEntity(const char* path, Position<float> position, Dimension<float> dimension)
    : RenderableEntity(path, position, dimension, Layer::Ground)
{

}
