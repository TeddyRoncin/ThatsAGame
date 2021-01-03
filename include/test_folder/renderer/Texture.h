#pragma once

#include "utils/Utils.h"

class Texture
{
public:
    Texture(char* pTexturePath, Dimension<float> pPosition, Dimension<float> pSize);
    char* GetTexturePath();
    Dimension<float> GetPosition();
    Dimension<float> GetSize();
    Dimension<float> ComputeActualPosition(Dimension<float> mapSize, Dimension<float> windowSize);
    Dimension<float> ComputeActualSize(Dimension<float> mapSize, Dimension<float> windowSize);
    void SetTexturePath(char* texturePath);
    void SetPosition(Dimension<float> position);
    void SetSize(Dimension<float> size);

private:
    const char* mTexturePath;
    Dimension<float> mPosition;
    Dimension<float> mSize;
};
