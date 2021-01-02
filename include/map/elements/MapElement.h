#pragma once

#include "entity/Entity.h"
#include "renderer/texture/Texture.h"

class MapElement : public Entity
{

public:
    // Create a constructor that takes in a size directly when created
    virtual ~MapElement() {}
    virtual bool operator()(Entity* entity) = 0;
    virtual const char* getTexturePath() const = 0;
    virtual const size_t getWidth() const = 0;
    virtual const size_t getHeight() const = 0;
    Texture&& getTexture(size_t x, size_t y) const;

};