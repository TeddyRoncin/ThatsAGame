#include "pch.h"

#include "map/elements/MapElement.h"

Texture&& MapElement::getTexture(size_t x, size_t y) const
{
    return Texture(getTexturePath(), 200 * x, 200 * y, 200, 200);
}
