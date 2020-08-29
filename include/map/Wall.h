#pragma once

#include "map/MapElement.h"

class Wall : public MapElement {

    virtual bool canEntityMoveOn(Entity entity);

};