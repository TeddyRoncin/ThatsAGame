#include "pch.h"

#include "test_folder/renderer/Texture.h"

Texture::Texture(const char* _texturePath, Position<float> _position, Dimension<float> _size)
    : texturePath(_texturePath), position(_position), size(_size)
{
}

Position<int> Texture::ComputeActualPosition(Dimension<int> mapSize, Dimension<int> windowSize) const
{
    return Position<int>(position.getX() * windowSize.getWidth() / mapSize.getWidth(),
                            position.getY() * windowSize.getHeight() / mapSize.getHeight());
}

Dimension<int> Texture::ComputeActualSize(Dimension<int> mapSize, Dimension<int> windowSize) const
{
    return Dimension<int>(size.getWidth() * windowSize.getWidth() / mapSize.getWidth(),
                            size.getHeight() * windowSize.getHeight() / mapSize.getHeight());
}