#pragma once

#include "entity/Entity.h"
#include "renderer/texture/Texture.h"

class MapElement
{

public:
    MapElement() {}
    virtual bool canEntityMoveOn(Entity* entity) = 0;
    virtual MapElement* copy() = 0;
    virtual const char* getTexturePath() const = 0;
    virtual Texture&& getTexture(size_t x, size_t y) const;

};