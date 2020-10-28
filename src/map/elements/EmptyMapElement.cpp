#include "pch.h"

#include "map/elements/EmptyMapElement.h"

EmptyMapElement::EmptyMapElement()
    :MapElement()
{}

EmptyMapElement::~EmptyMapElement()
{}

bool EmptyMapElement::operator()(Entity* entity)
{
    return true;
}

const char* EmptyMapElement::getTexturePath() const
{
    return "assets/textures/empty_map_element.png";
}

const size_t EmptyMapElement::getWidth() const
{
    return 200;
}

const size_t EmptyMapElement::getHeight() const
{
    return 200;
}
