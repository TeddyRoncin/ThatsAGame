#pragma once

#include "../Entity/Entity.h"

class MapElement 
{
public:
    MapElement() {}
    virtual bool canEntityMoveOn(Entity entity) = 0;
};