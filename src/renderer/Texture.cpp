#include "pch.h"

#include "renderer/Texture.h"
#include "renderer/TextureManager.h"

Texture::Texture(const char* _texturePath, Position<float> _position, Dimension<float> _size)
    : texturePath(_texturePath), position(_position), size(_size)
{
    //std::cout << "Texture";
    TextureManager::LoadTexture(texturePath);
}

Texture::~Texture()
{
    TextureManager::UnloadTexture(texturePath);
}

Position<int> Texture::ComputeActualPosition(Dimension<int> mapSize, Dimension<int> windowSize) const
{
    return Position<int>(std::ceil(position.getX() * windowSize.getWidth() / mapSize.getWidth()),
                            std::ceil(position.getY() * windowSize.getHeight() / mapSize.getHeight()));
}

Dimension<int> Texture::ComputeActualSize(Dimension<int> mapSize, Dimension<int> windowSize) const
{
    return Dimension<int>(std::ceil(size.getWidth() * windowSize.getWidth() / mapSize.getWidth()),
                            std::ceil(size.getHeight() * windowSize.getHeight() / mapSize.getHeight()));
}
