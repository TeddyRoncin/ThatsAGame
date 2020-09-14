#include "pch.h"

#include "entity/Renderable.h"

Renderable::Renderable(const char* name, float x, float y, float width, float height, const char* sprite)
	:Entity(name, x, y), m_dim(width,height), m_sprite(sprite)
{
}

Renderable::~Renderable()
{
}

void Renderable::Render(SDL_Renderer* renderer) const
{
	Texture entity(renderer, m_sprite, (int)m_pos.getX(), (int)m_pos.getY(), (int)m_dim.getWidth(), (int)m_dim.getHeight());
	SDL_RenderCopy(renderer, entity.m_Texture, nullptr, &entity.m_Rect);
	SDL_RenderPresent(renderer);
}
