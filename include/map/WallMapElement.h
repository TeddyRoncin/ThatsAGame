#pragma once

#include "map/MapElement.h"

class WallMapElement : public MapElement {

public:
    virtual bool canEntityMoveOn(Entity entity);
    virtual void display();
    virtual MapElement* copy();

};