#pragma once

#include "map/elements/MapElement.h"

class WallMapElement : public MapElement {

public:
    WallMapElement();
    virtual ~WallMapElement() override;
    virtual bool operator()(Entity* entity);
    virtual const char* getTexturePath() const;
    virtual const size_t getWidth() const override;
    virtual const size_t getHeight() const override;

};
