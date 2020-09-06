#pragma once

#include "map/MapElement.h"
#include "renderer/texture/Texture.h"

class WallMapElement : public MapElement {

public:
    virtual bool canEntityMoveOn(Entity* entity);
    virtual const char* getTexturePath() const;
    virtual const size_t getWidth() const override;
    virtual const size_t getHeight() const override;

};
