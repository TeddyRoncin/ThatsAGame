#include "pch.h"

#include "entity/player/Player.h"

player::player(const char* _directory, float _x, float _y, float _width, float _height)
	:EventListener(this), pos(_x, _y), dim(_width, _height), directory(_directory), 
	texture(directory, pos.getX(), pos.getY())
{
}

void player::handle()
{
	switch(m_Action) {
		case Action::PlayerUp:
		{
			pos.position.second -= 0.5f;
			break;
		}
		
		case Action::PlayerDown:
		{
			pos.position.second += 0.5f;
			break;
		}
		
		case Action::PlayerRight:
		{
			pos.position.first += 0.5f;
			break;
		}
		
		case Action::PlayerLeft:
		{
			pos.position.first -= 0.5f;
			break;
		}

		case Action::PlayerAct:
		{
			std::cout << "> Player Action" << std::endl;
			break;
		}
		
		case Action::PlayerInventory:
		{
			std::cout << "> Open Inventory" << std::endl;
			break;
		}
	};
}

void player::Render(SDL_Renderer* renderer)
{
	texture.m_Rect.x = pos.getX();
	texture.m_Rect.y = pos.getY();
	texture.Bind(renderer);
	SDL_RenderCopy(renderer, texture.m_Texture, nullptr, &texture.m_Rect);
}
