#include "pch.h"

#include "map/WallMapElement.h"

bool WallMapElement::canEntityMoveOn(Entity* entity)
{
    return false;
}

MapElement* WallMapElement::copy()
{
    return new WallMapElement();
}

const char* WallMapElement::getTexturePath() const
{
    return "assets/textures/wall_map_element.png";
}

