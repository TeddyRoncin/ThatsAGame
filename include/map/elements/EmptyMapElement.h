#pragma once

#include "map/elements/MapElement.h"

class EmptyMapElement : public MapElement {
public:
    EmptyMapElement();
    virtual ~EmptyMapElement() override;
};
