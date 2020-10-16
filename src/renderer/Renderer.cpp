#include "pch.h"
#include "renderer/Renderer.h"
#include "map/WallMapElement.h"

Renderer::Renderer()
	:Context(SDL_INIT_VIDEO), m_Window(nullptr), m_Renderer(nullptr)
{
	m_Window = SDL_CreateWindow("Render Window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,600,600,SDL_WindowFlags::SDL_WINDOW_RESIZABLE);
	if(!m_Window)
	{
		// std::cerr << "SDL_CreateWindowError : " << SDL_GetError() << std::endl;
	}
	m_Renderer = SDL_CreateRenderer(m_Window,-1,0);
	if(!m_Renderer)
	{
		// std::cerr << "SDL_CreateRendererError: " << SDL_GetError() << std::endl;
	}
}

Renderer::~Renderer()
{
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);
}

void Renderer::Clear()
{
	SDL_SetRenderDrawColor(m_Renderer,0,0,0,255);
	SDL_RenderClear(m_Renderer);
	SDL_RenderPresent(m_Renderer);
}

void Renderer::Present()
{
	SDL_RenderPresent(m_Renderer);
}

void Renderer::UpdateRender()
{
	for(auto& Layer : m_Textures)
	{
		for(auto& texture : Layer)
		{
			SDL_RenderCopy(m_Renderer, texture.m_Texture, nullptr, &texture.m_Rect);
		}
	}
}

void Renderer::AddTexture(Texture&& texture, Layer layer)
{
	if(texture.needBinding)
		texture.Bind(m_Renderer);
	m_Textures[layer].emplace_back(texture);
}

void Renderer::AddTexture(const char* dir, size_t x, size_t y, size_t width, size_t height, Layer layer)
{
	m_Textures[layer].emplace_back(Texture(m_Renderer, dir, x, y, width, height));
}

void Renderer::AddMap(const Map& map)
{
	m_Textures[Layer::Background].emplace(m_Textures[Layer::Background].begin(), Texture(m_Renderer, map.getBackgroundPath().c_str(), 0, 0, SDL_GetWindowSurface(m_Window)->w, SDL_GetWindowSurface(m_Window)->h));
	//auto test = map.getMapElements();
	size_t xEnlargement = SDL_GetWindowSurface(m_Window)->w / map.getWidth();
	size_t yEnlargement = SDL_GetWindowSurface(m_Window)->h / map.getHeight();
	for(size_t i (0); i < map.getWidth(); i++)
	{
		for(size_t k(0); k < map.getHeight(); k++)
		{
			MapElement* me = map.getAt(i, k);
			(*me).getHeight();
			std::cout << map.getAt(i, k)->getTexturePath() << std::endl;
			std::cout << Texture(m_Renderer, map.getAt(i, k)->getTexturePath(),
					xEnlargement * i, yEnlargement * k,
					xEnlargement, yEnlargement
				).m_Rect.h << std::endl;
			m_Textures[Layer::Background].emplace(m_Textures[Layer::Background].end(),
				Texture(m_Renderer, map.getAt(i, k)->getTexturePath(),
					xEnlargement * i, yEnlargement * k,
					xEnlargement, yEnlargement
				)
			);
		}
	}
}

void Renderer::RenderEntity(const Entity& ent, size_t mapWidth, size_t mapHeight)
{
	ent.Render(m_Renderer, SDL_GetWindowSurface(m_Window)->w / mapWidth, SDL_GetWindowSurface(m_Window)->h / mapHeight);
}
