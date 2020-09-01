#pragma once

#include "map/MapElement.h"
#include "entity/Entity.h"

class EmptyMapElement : public MapElement {

public:
    virtual bool canEntityMoveOn(Entity* entity);
    virtual void display();
    virtual MapElement* copy();

};