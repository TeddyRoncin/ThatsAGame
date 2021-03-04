#include "pch.h"

#include "renderer/Renderer.h"
#include "map/Map.h"

Renderer::Renderer(const ApplicationState* const state, SDL_Window* window)
	: m_State(state), m_WindowSize(0, 0), m_Renderer(SDL_CreateRenderer(window,-1,0))
{
	if(!m_Renderer)
	{
		std::cerr << "SDL_CreateRendererError: " << SDL_GetError() << std::endl;
	}
	TextureManager::Init(m_Renderer);
}

Renderer::~Renderer()
{
	TextureManager::Destroy();
	SDL_DestroyRenderer(m_Renderer);
}

void Renderer::SetWindowSize(Dimension<int> newSize)
{
	m_WindowSize = newSize;
}

void Renderer::Render()
{
	SDL_SetRenderDrawColor(m_Renderer,0,0,0,255);
	SDL_RenderClear(m_Renderer);
	switch (*m_State) {
		case ApplicationState::Home: RenderHome(); break;
		case ApplicationState::Game: RenderGame(); break;
		default: std::cerr << "Unknow application state : " << *m_State << ". Skipping render for this frame" << std::endl;
	}
	SDL_RenderPresent(m_Renderer);
}

void Renderer::RenderHome()
{
}

void Renderer::RenderGame()
{
	RenderTextures();
	SDL_RenderPresent(m_Renderer);
}

void Renderer::RenderTextures()
{
	auto& textures = TextureManager::GetTextures();
	Position<int> offset {0, 0};
	int delta = m_WindowSize.getWidth() / Map::Width() - m_WindowSize.getHeight() / Map::Height();
	Dimension<int> renderSize = m_WindowSize;
	if (delta < 0)
	{
		renderSize.dimension.second = (float) m_WindowSize.getWidth() / Map::Width() * Map::Height();
		offset.position.second = (m_WindowSize.getHeight() - renderSize.dimension.second) >> 1;
	}
	else
	{
		renderSize.dimension.first = (float) m_WindowSize.getHeight() / Map::Height() * Map::Width();
		offset.position.first = (m_WindowSize.getWidth() - renderSize.dimension.first) >> 1;
	}
	for(auto& layer : textures)
	{
		for(auto& textureinfo : layer)
		{
			if (textureinfo.second->drawOnTheFly)
			{
				textureinfo.second->Draw(m_Renderer);
			}
			else
			{
				auto[x, y] = textureinfo.second->ComputeActualPosition({Map::Width(), Map::Height()}, renderSize).getPosition();
				auto[width, height] = textureinfo.second->ComputeActualSize({Map::Width(), Map::Height()}, renderSize).getDimension();
				SDL_Rect distrect{x + offset.getX(), y + offset.getY(), width, height};
				SDL_RenderCopy(m_Renderer, textureinfo.second->texture, nullptr, &distrect);
			}
		}
	}
}
