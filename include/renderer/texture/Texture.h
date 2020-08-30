#pragma once

#include <SDL2/SDL_image.h>

class Texture
{
public:
	Texture(SDL_Renderer* renderer, const char* dir, size_t x, size_t y, size_t width, size_t height);
	~Texture();
	SDL_Texture* m_Texture;
	SDL_Rect m_Rect;
};
