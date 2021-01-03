#include "pch.h"

#include "test_folder/renderer/Texture.h"

Texture::Texture(char* texturePath, Position<float> position, Dimension<float> size)
    : mTexturePath(texturePath), mPosition(position), mSize(size)
{
}

const char* Texture::GetTexturePath()
{
    return mTexturePath;
}

Position<float> Texture::GetPosition()
{
    return mPosition;
}

Dimension<float> Texture::GetSize()
{
    return mSize;
}

Dimension<float> Texture::ComputeActualPosition(Dimension<float> mapSize, Dimension<float> windowSize)
{
    return Dimension<float>(mPosition.getX() * windowSize.getWidth() / mapSize.getWidth(),
                            mPosition.getY() * windowSize.getHeight() / mapSize.getHeight());
}

Dimension<float> Texture::ComputeActualSize(Dimension<float> mapSize, Dimension<float> windowSize)
{
    return Dimension<float>(mSize.getWidth() * windowSize.getWidth() / mapSize.getWidth(),
                            mSize.getHeight() * windowSize.getHeight() / mapSize.getHeight());
}

void Texture::SetTexturePath(char* texturePath)
{
    mTexturePath = texturePath;
}

void Texture::SetPosition(Position<float> position)
{
    mPosition = position;
}

void Texture::SetSize(Dimension<float> size)
{
    mSize = size;
}