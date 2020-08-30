#pragma once

#include "MapElement.h"
#include "Entity/Entity.h"

#include <string>


class Wall : public MapElement
{
    virtual bool canEntityMoveOn(Entity entity);
};