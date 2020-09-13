#pragma once

#include "map/MapElement.h"
#include "renderer/texture/Texture.h"

class EmptyMapElement : public MapElement {

public:
    EmptyMapElement() {}
    virtual bool canEntityMoveOn(Entity* entity) override;
    virtual MapElement* copy() override;
    virtual const char* getTexturePath() const override;
    //virtual Texture&& getTexture(size_t x, size_t y) const;

};