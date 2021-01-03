#pragma once

struct Texture
{
public:
    Texture(char* _texturePath, Position<float> _position, Dimension<float> _size);

public:
    Position<int> ComputeActualPosition(Dimension<int> mapSize, Dimension<int> windowSize) const;
    Dimension<int> ComputeActualSize(Dimension<int> mapSize, Dimension<int> windowSize) const;

public:
    const char* texturePath;
    Position<float> position;
    Dimension<float> size;
};
