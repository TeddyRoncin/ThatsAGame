#pragma once

#include "map/MapElement.h"
//#include "../Entity/Entity.h"

class Entity;

class EmptyMapElement : public MapElement 
{
    virtual bool canEntityMoveOn(Entity entity);
};