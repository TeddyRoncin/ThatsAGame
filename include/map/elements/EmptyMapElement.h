#pragma once

#include "map/elements/MapElement.h"

class EmptyMapElement : public MapElement {
public:
    EmptyMapElement(Position<float> position);
    virtual ~EmptyMapElement() override;

    virtual bool operator()(Entity& entity) override;
};
