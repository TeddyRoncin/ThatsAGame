#include "pch.h"

#include "map/elements/WallMapElement.h"

WallMapElement::WallMapElement(Position<float> position)
    :MapElement("assets/textures/wall_map_element.png", position, {1.0f, 1.0f})
{}

WallMapElement::~WallMapElement()
{}

bool WallMapElement::operator()(const Entity& entity)
{
    return false;
}