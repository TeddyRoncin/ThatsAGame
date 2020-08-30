#include <iostream>

#include "renderer/texture/Texture.h"

Texture::Texture(SDL_Renderer* renderer, const char* dir, size_t x, size_t y, size_t width, size_t height)
{
	m_Rect = SDL_Rect{(int)x, (int)y, (int)width, (int)height};
	m_Texture = IMG_LoadTexture(renderer, dir);
	if(!m_Texture)
	{
		std::cerr << "IMG_LoadTextureError : " << SDL_GetError() << std::endl;
	}
	if(width == 0 || height == 0)
	{
		SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_Rect.w, &m_Rect.h);
	}
	SDL_RenderCopy(renderer, m_Texture, nullptr, &m_Rect);
}

Texture::~Texture()
{
	SDL_DestroyTexture(m_Texture);
}
