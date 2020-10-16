#include "pch.h"

#include "entity/Entity.h"

Entity::Entity(const char* name, float x, float y)
	:m_name(name), m_pos(x,y)
{
}

Entity::~Entity()
{
}

void Entity::Render(SDL_Renderer* renderer, int xEnlargement, int yEnlargement) const
{
	TTF_Font* Sans = TTF_OpenFont("assets/font/Vogue.ttf", 24);

	SDL_Color White = {255, 255, 255};

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "This", White);

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_Rect Message_rect;
	Message_rect.x = (int)m_pos.getX();
	Message_rect.y = (int)m_pos.getY();
	Message_rect.w = 190;
	Message_rect.h = 50;

	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}
