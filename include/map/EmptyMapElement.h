#pragma once

#include "map/MapElement.h"

class EmptyMapElement : public MapElement {

    virtual bool canEntityMoveOn(Entity entity);

};