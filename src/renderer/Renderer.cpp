#include "pch.h"
#include "renderer/Renderer.h"

Renderer::Renderer()
	:Context(SDL_INIT_VIDEO), m_Window(nullptr), m_Renderer(nullptr)
{
	m_Window = SDL_CreateWindow("Render Window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,300,300,SDL_WindowFlags::SDL_WINDOW_SHOWN);
	if(!m_Window)
	{
		std::cerr << "SDL_CreateWindowError : " << SDL_GetError() << std::endl;
	}
	m_Renderer = SDL_CreateRenderer(m_Window,-1,0);
	if(!m_Renderer)
	{
		std::cerr << "SDL_CreateRendererError: " << SDL_GetError() << std::endl;
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
}

void Renderer::Render()
{
	for(auto& Layer : m_Textures)
	{
		for(auto& texture : Layer)
		{
			SDL_SetRenderTarget(m_Renderer, texture.m_Texture);
		}
	}
	SDL_RenderPresent(m_Renderer);
}

void Renderer::AddTexture(Texture&& texture, Layer layer)
{
	if(texture.needBinding)
		texture.Bind(m_Renderer);
	m_Textures[layer].emplace(texture);
}

void Renderer::AddTexture(const char* dir, size_t x, size_t y, size_t width, size_t height, Layer layer)
{
	m_Textures[layer].emplace(Texture(m_Renderer, dir, x, y, width, height));
}

void Renderer::RenderMap(const Map& map)
{
	m_Textures[Layer::Background].emplace(Texture(m_Renderer, map.getBackgroundPath().c_str(), 0, 0));
	int x(0), y(0);
	for(std::vector<MapElement*> raw : map.getMapElements())
	{
		for(MapElement* element : raw)
		{
			Texture&& temp = element->getTexture(x,y);
			if(temp.needBinding)
			{
				temp.Bind(m_Renderer);
			}
			m_Textures[Layer::Background].emplace(temp);
			y++;
		}
		x++;
	}
}

