#include "pch.h"

#include "map/EmptyMapElement.h"

bool EmptyMapElement::canEntityMoveOn(Entity* entity)
{
    return true;
}

MapElement* EmptyMapElement::copy()
{
    return new EmptyMapElement();
}

const char* EmptyMapElement::getTexturePath() const
{
    return "assets/textures/empty_map_element.png";
}