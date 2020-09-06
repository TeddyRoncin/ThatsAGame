#include "pch.h"

#include "map/EmptyMapElement.h"

bool EmptyMapElement::canEntityMoveOn(Entity* entity)
{
    return true;
}

const char* EmptyMapElement::getTexturePath() const
{
    return "assets/textures/empty_map_element.png";
}

const size_t EmptyMapElement::getWidth() const
{
    return 100;
}

const size_t EmptyMapElement::getHeight() const
{
    return 100;
}
