#pragma once

//#include "../Entity/Entity.h"
class Entity{};

class MapElement 
{
public:
    MapElement() {}
    virtual bool canEntityMoveOn(Entity entity) = 0;
};