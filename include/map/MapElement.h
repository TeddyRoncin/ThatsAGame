#pragma once

#include "entity/Entity.h"
#include "renderer/texture/Texture.h"

class MapElement
{

public:
    virtual ~MapElement() {}
    virtual bool canEntityMoveOn(Entity* entity) = 0;
    virtual const char* getTexturePath() const = 0;
    virtual const size_t getWidth() const = 0;
    virtual const size_t getHeight() const = 0;
    Texture&& getTexture(size_t x, size_t y) const;


};