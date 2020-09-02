#pragma once

#include "map/MapElement.h"

class WallMapElement : public MapElement {

public:
    virtual bool canEntityMoveOn(Entity* entity);
    virtual MapElement* copy();
    virtual const char* getTexturePath() const;

};