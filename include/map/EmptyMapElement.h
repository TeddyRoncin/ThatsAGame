#pragma once

#include "map/MapElement.h"
#include "renderer/texture/Texture.h"

class EmptyMapElement : public MapElement {

public:
    EmptyMapElement();
    virtual ~EmptyMapElement() override;
    virtual bool canEntityMoveOn(Entity* entity);
    virtual const char* getTexturePath() const;
    virtual const size_t getWidth() const override;
    virtual const size_t getHeight() const override;

};