#pragma once

struct Texture
{
public:
    Texture(const char* _texturePath, Position<float> _position, Dimension<float> _size);
    ~Texture();

public:
    Position<int> ComputeActualPosition(Dimension<int> mapSize, Dimension<int> windowSize) const;
    Dimension<int> ComputeActualSize(Dimension<int> mapSize, Dimension<int> windowSize) const;

public:
    const char* const texturePath;
    Position<float> position;
    Dimension<float> size;
};
