#pragma once

#include "map/MapElement.h"
#include "entity/Entity.h"
#include "renderer/texture/Texture.h"

class EmptyMapElement : public MapElement {

public:
    virtual bool canEntityMoveOn(Entity* entity);
    virtual MapElement* copy();
    virtual const char* getTexturePath() const;
    //virtual Texture&& getTexture(size_t x, size_t y) const;

};