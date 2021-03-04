#pragma once

#include "renderer/Layer.h"

struct Texture
{
public:
	Texture(const Position<float>* _position, const Dimension<float>* _size, bool _drawOnTheFly = true);
	Texture(const Position<float>* _position, const Dimension<float>* _size, SDL_Texture* _texture, const char* _path);
	~Texture();

public:
	virtual void Draw(SDL_Renderer* renderer) {};
	Position<int> ComputeActualPosition(Dimension<int> mapSize, Dimension<int> windowSize) const;
	Dimension<int> ComputeActualSize(Dimension<int> mapSize, Dimension<int> windowSize) const;

public:
	SDL_Texture* texture;
	const char* texture_path;
	const Position<float>* position;
	const Dimension<float>* size;
	bool drawOnTheFly;
};
