#include <iostream>

#include "map/WallMapElement.h"

bool WallMapElement::canEntityMoveOn(Entity entity) {
    return false;
}

void WallMapElement::display() {
    std::cout << "WallMapElement";
}

MapElement* WallMapElement::copy()
{
    return new WallMapElement();
}