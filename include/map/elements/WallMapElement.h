#pragma once

#include "map/elements/MapElement.h"

class WallMapElement : public MapElement {
public:
    WallMapElement();
    virtual ~WallMapElement() override;
    virtual bool operator()(Entity* entity);
};
