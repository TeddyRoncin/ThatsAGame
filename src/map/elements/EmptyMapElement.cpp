#include "pch.h"

#include "map/elements/EmptyMapElement.h"

EmptyMapElement::EmptyMapElement(Position<float> position)
    :MapElement("assets/textures", position, {1.0f, 1.0f})
{}

EmptyMapElement::~EmptyMapElement()
{}

bool EmptyMapElement::operator()(const Entity& entity)
{
    return true;
}
