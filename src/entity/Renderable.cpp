#include "pch.h"

#include "entity/Renderable.h"

Renderable::Renderable(const char* name, float x, float y, float width, float height, const char* sprite)
	:Entity(name, x, y), m_dim(width,height), m_sprite(sprite)
{
}

Renderable::~Renderable()
{
}

void Renderable::Render(SDL_Renderer* renderer, int xEnlargement, int yEnlargement) const
{
	Texture entity(renderer, m_sprite, m_pos.getX() * xEnlargement, m_pos.getY() * yEnlargement, m_dim.getWidth() * xEnlargement, m_dim.getHeight() * yEnlargement);
	SDL_RenderCopy(renderer, entity.m_Texture, nullptr, &entity.m_Rect);
	SDL_RenderPresent(renderer);
}
