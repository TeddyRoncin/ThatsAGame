#pragma once

struct Texture
{
public:
    Texture(const Position<float>* _position, const Dimension<float>* _size, SDL_Texture* _texture, const char* path);
    ~Texture();

public:
    Position<int> ComputeActualPosition(Dimension<int> mapSize, Dimension<int> windowSize) const;
    Dimension<int> ComputeActualSize(Dimension<int> mapSize, Dimension<int> windowSize) const;

public:
    SDL_Texture* texture;
    const char* texture_path;
    const Position<float>* position;
    const Dimension<float>* size;
};
