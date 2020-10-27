#pragma once

#include "map/elements/MapElement.h"

class EmptyMapElement : public MapElement {

public:
    EmptyMapElement();
    virtual ~EmptyMapElement() override;
    virtual bool operator()(Entity* entity);
    virtual const char* getTexturePath() const;
    virtual const size_t getWidth() const override;
    virtual const size_t getHeight() const override;

};