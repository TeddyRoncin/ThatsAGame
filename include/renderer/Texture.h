#pragma once

#include "renderer/Layer.h"

struct TextureInfo
{
	int current_frame[2];
	int offsetx, offsety;
};

struct Texture
{
public:
	Texture(const Position<float>* _position, const Dimension<float>* _size, SDL_Texture* _texture, void* _texture_info = nullptr);
	~Texture();

public:
	Position<int> ComputeActualPosition(Dimension<int> mapSize, Dimension<int> windowSize) const;
	Dimension<int> ComputeActualSize(Dimension<int> mapSize, Dimension<int> windowSize) const;
	SDL_Rect* ComputeActualSrcRect() const;

public:
	SDL_Texture* texture;
	mutable SDL_Rect src_rect;
	void* texture_info;
	const char* texture_path;
	const Position<float>* position;
	const Dimension<float>* size;
};
