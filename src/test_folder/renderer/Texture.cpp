#include "pch.h"

#include "test_folder/renderer/Texture.h"

Texture::Texture(char* _texturePath, Position<float> _position, Dimension<float> _size)
    : texturePath(_texturePath), position(_position), size(_size)
{
}

Position<float> Texture::ComputeActualPosition(Dimension<float> mapSize, Dimension<float> windowSize) const
{
    return Position<float>(position.getX() * windowSize.getWidth() / mapSize.getWidth(),
                            position.getY() * windowSize.getHeight() / mapSize.getHeight());
}

Dimension<float> Texture::ComputeActualSize(Dimension<float> mapSize, Dimension<float> windowSize) const
{
    return Dimension<float>(size.getWidth() * windowSize.getWidth() / mapSize.getWidth(),
                            size.getHeight() * windowSize.getHeight() / mapSize.getHeight());
}