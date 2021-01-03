#include "pch.h"

#include "test_folder/renderer/Texture.h"

Texture::Texture(char* texturePath, Dimension<float> position, Dimension<float> size)
    : mPosition(position), mSize(size)
{
}

char* Texture::GetTexturePath()
{
    return mTexturePath;
}

Dimension<float> Texture::GetPosition()
{
    return mPosition;
}

Dimension<float> Texture::GetSize()
{
    return mSize;
}

Dimension<float> Texture::ComputeActualPosition(Dimension<float> mapSize, Dimension<float> windowSize)
{
    return Dimension<float>(mPosition.getWidth() * windowSize.getWidth() / mapSize.getWidth(),
                            mPosition.getHeight() * windowSize.getHeight() / mapSize.getHeight());
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

void Texture::SetPosition(Dimension<float> position)
{
    mPosition = position;
}

void Texture::SetSize(Dimension<float> size)
{
    mSize = size;
}