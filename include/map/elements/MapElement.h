#pragma once

#include "entity/Entity.h"

class MapElement
{
public:
    virtual ~MapElement() {}
    virtual bool operator()(Entity* entity) = 0;
};
