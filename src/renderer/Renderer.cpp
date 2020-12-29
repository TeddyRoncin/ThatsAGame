#include "pch.h"
#include "renderer/Renderer.h"

Renderer::Renderer()
	:Context(SDL_INIT_VIDEO), m_Window(nullptr), m_Renderer(nullptr)
{
	m_Window = SDL_CreateWindow("Render Window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WindowFlags::SDL_WINDOW_RESIZABLE);
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
	for(size_t y(0); y < map.Height(); y++)
	{
		for(size_t x(0); x < map.Width(); x++)
		{
			m_Textures[Layer::Background].emplace_back(Texture(
				m_Renderer, map[x + y * map.Height()]->getTexturePath(),
				map[x + y * map.Height()]->getWidth()*x, map[x + y * map.Height()]->getHeight()*y,
				map[x + y * map.Height()]->getWidth(), map[x + y * map.Height()]->getHeight()
			));
		}
	}
}

void Renderer::RenderPlayer(Player& p)
{
	// p.Render(m_Renderer);
}

void Renderer::RenderEntity(const Entity& ent)
{
	ent.Render(m_Renderer);
}
