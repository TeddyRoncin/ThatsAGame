#include "pch.h"

#include "map/elements/WallMapElement.h"

WallMapElement::WallMapElement()
{}

WallMapElement::~WallMapElement()
{}

bool WallMapElement::operator()(Entity* entity)
{
    return false;
}
