#pragma once

#include "map/MapElement.h"
#include "../Entity/Entity.h"

class EmptyMapElement : public MapElement 
{
    virtual bool canEntityMoveOn(Entity entity);
};