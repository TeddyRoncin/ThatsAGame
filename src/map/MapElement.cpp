#include "pch.h"

#include "map/MapElement.h"

Texture&& MapElement::getTexture(size_t x, size_t y) const
{
    std::cout << "juste avant" << std::endl;
    std::cout << this->getTexturePath() << std::endl;
    std::cout << "juste apres" << std::endl;
    //Texture texture(getTexturePath(), 100 * x, 100 * y, 100, 100);
    return Texture(getTexturePath(), 100 * x, 100 * y, 100, 100);
}
