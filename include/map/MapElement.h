#pragma once

#include "entity/Entity.h"

class MapElement {

public:
    MapElement() {}
    virtual bool canEntityMoveOn(Entity* entity) = 0;
    virtual void display() = 0;
    virtual MapElement* copy() = 0;

};