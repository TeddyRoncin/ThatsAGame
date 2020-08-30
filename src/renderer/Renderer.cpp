#include <iostream>
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
	for(auto texture : m_Textures)
	{
		SDL_SetRenderTarget(m_Renderer, texture.second.m_Texture);
	}
	SDL_RenderPresent(m_Renderer);
}

void Renderer::AddTexture(size_t x, size_t y, const char* name, size_t width, size_t height)
{
	m_Textures.emplace(name, Texture(m_Renderer, name, x, y, width, height));
}

void Renderer::RemoveTexture(const char* name)
{
	m_Textures.erase(name);
}

