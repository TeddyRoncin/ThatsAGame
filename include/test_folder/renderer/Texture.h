#pragma once

struct Texture
{
public:
    Texture(char* _texturePath, Position<float> _position, Dimension<float> _size);

public:
    Position<float> ComputeActualPosition(Dimension<float> mapSize, Dimension<float> windowSize) const;
    Dimension<float> ComputeActualSize(Dimension<float> mapSize, Dimension<float> windowSize) const;

public:
    const char* texturePath;
    Position<float> position;
    Dimension<float> size;
};
