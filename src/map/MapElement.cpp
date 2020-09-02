#include "pch.h"

#include "map/MapElement.h"

Texture&& MapElement::getTexture(size_t x, size_t y) const
{
    return Texture(getTexturePath(), 100 * x, 100 * y, 100, 100);
}