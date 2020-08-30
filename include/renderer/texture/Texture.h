#pragma once

#include <SDL2/SDL_image.h>

class Texture
{
public:
	Texture(SDL_Renderer* renderer, const char* dir, int x, int y, int width, int height);
	~Texture();
	SDL_Texture* m_Texture;
	SDL_Rect m_Rect;
	const char* m_Dir;
};
