#include <iostream>

#include "map/EmptyMapElement.h"

bool EmptyMapElement::canEntityMoveOn(Entity* entity)
{
    return true;
}

void EmptyMapElement::display()
{
    std::cout << "EmptyMapElement";
}

MapElement* EmptyMapElement::copy()
{
    return new EmptyMapElement();
}