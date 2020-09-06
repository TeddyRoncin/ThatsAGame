#include "pch.h"

#include "map/WallMapElement.h"

bool WallMapElement::canEntityMoveOn(Entity* entity)
{
    return false;
}

const char* WallMapElement::getTexturePath() const
{
    return "assets/textures/wall_map_element.png";
}

const size_t WallMapElement::getWidth() const
{
    return 100;
}

const size_t WallMapElement::getHeight() const
{
    return 100;
}
