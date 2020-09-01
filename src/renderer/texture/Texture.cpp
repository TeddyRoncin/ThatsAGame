#include "pch.h"

#include "renderer/texture/Texture.h"

Texture::Texture(const char* dir, SDL_Renderer* renderer)
	:m_Surface(nullptr), m_Texture(nullptr)
{
	if(!renderer)
	{
		needBinding = true;
		m_Surface = IMG_Load(dir);
		if(!m_Surface)
		{
			std::cerr << "IMG_LoadError (for SDL_Surface): " << IMG_GetError() << std::endl;
		}
	} else {
		m_Texture = IMG_LoadTexture(renderer, dir);
		if(!m_Texture)
		{
			std::cerr << "IMG_LoadTextureError : " << IMG_GetError() << std::endl;
		}
		SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_Rect.w, &m_Rect.h);
		SDL_RenderCopy(renderer, m_Texture, nullptr, &m_Rect);
	}
}

Texture::Texture(SDL_Renderer* renderer, const char* dir, size_t x, size_t y, size_t width, size_t height)
	:m_Surface(nullptr), m_Texture(IMG_LoadTexture(renderer, dir)), m_Rect{(int)x, (int)y, (int)width, (int)height}
{
	if(!m_Texture)
	{
		std::cerr << "IMG_LoadTextureError : " << IMG_GetError() << std::endl;
	}
	if(width == 0 || height == 0)
	{
		SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_Rect.w, &m_Rect.h);
	}
	SDL_RenderCopy(renderer, m_Texture, nullptr, &m_Rect);
}

Texture::Texture(Texture&& texture)
	:m_Surface(texture.m_Surface), m_Texture(texture.m_Texture), m_Rect(texture.m_Rect), needBinding(texture.needBinding)
{
	texture.m_Surface = nullptr;
	texture.m_Texture = nullptr;
	texture.m_Rect = SDL_Rect{0,0,0,0};
}

Texture::~Texture()
{
	if(needBinding)
		SDL_FreeSurface(m_Surface);
	else
		SDL_DestroyTexture(m_Texture);
}

void Texture::Bind(SDL_Renderer* renderer)
{
	if(!needBinding)
		return;
	if(m_Rect.w == 0 || m_Rect.h == 0)
	{
		SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_Rect.w, &m_Rect.h);
	}
	SDL_RenderCopy(renderer, m_Texture, nullptr, &m_Rect);
}

bool Texture::operator<(const Texture& texture) const
{
	return ( (m_Rect.w > texture.m_Rect.w) && (m_Rect.h > texture.m_Rect.h) );
}
