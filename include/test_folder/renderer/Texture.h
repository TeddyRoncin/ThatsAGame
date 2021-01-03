#pragma once

class Texture
{
public:
    Texture(char* pTexturePath, Position<float> pPosition, Dimension<float> pSize);
    const char* GetTexturePath();
    Position<float> GetPosition();
    Dimension<float> GetSize();
    Dimension<float> ComputeActualPosition(Dimension<float> mapSize, Dimension<float> windowSize);
    Dimension<float> ComputeActualSize(Dimension<float> mapSize, Dimension<float> windowSize);
    void SetTexturePath(char* texturePath);
    void SetPosition(Position<float> position);
    void SetSize(Dimension<float> size);

private:
    const char* mTexturePath;
    Position<float> mPosition;
    Dimension<float> mSize;
};
