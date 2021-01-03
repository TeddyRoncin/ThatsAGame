#pragma once

#include "map/elements/MapElement.h"

class WallMapElement : public MapElement {
public:
    WallMapElement(Position<float> position);
    virtual ~WallMapElement() override;

    virtual bool operator()(const Entity& entity) override;
};
