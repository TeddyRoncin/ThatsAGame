#include "pch.h"

#include "renderer/Renderer.h"
#include "map/Map.h"

Position<int> Renderer::m_CellOffset = { 0, 0 };
Dimension<int> Renderer::m_RenderCellSize = { 0, 0 };

Renderer::Renderer(const ApplicationState* const state, SDL_Window* window)
	: m_State(state), m_WindowSize(0, 0), m_Renderer(SDL_CreateRenderer(window,-1,0)), m_Delta(-1)
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
	if(Map::Width() != 0 && Map::Height() != 0)
	{
		int delta = m_WindowSize.getWidth() / Map::Width() - m_WindowSize.getHeight() / Map::Height();
		if(delta != m_Delta)
		{
			m_CellOffset = {0, 0};
			m_RenderCellSize = m_WindowSize;
			if (delta < 0)
			{
				m_RenderCellSize.dimension.second = (float) m_WindowSize.getWidth() / Map::Width() * Map::Height();
				m_CellOffset.position.second = (m_WindowSize.getHeight() - m_RenderCellSize.dimension.second) >> 1;
			}
			else
			{
				m_RenderCellSize.dimension.first = (float) m_WindowSize.getHeight() / Map::Height() * Map::Width();
				m_CellOffset.position.first = (m_WindowSize.getWidth() - m_RenderCellSize.dimension.first) >> 1;
			}
		}
		m_Delta = delta;
	}
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
	int i = 0;
	for(auto& layer : textures)
	{
		for(auto& textureinfo : layer)
		{
			auto[x, y] = textureinfo.second.ComputeActualPosition({Map::Width(), Map::Height()}, m_RenderCellSize).getPosition();
			auto[width, height] = textureinfo.second.ComputeActualSize({Map::Width(), Map::Height()}, m_RenderCellSize).getDimension();
			DrawTexture(textureinfo.second, x + m_CellOffset.getX(), y + m_CellOffset.getY(), width, height);
		}
		i++;
	}
	auto& uiTextures = TextureManager::GetUITextures();
	for (auto texture : uiTextures)
	{
		auto[x, y] = (std::pair<int, int>) texture.second.position->position;
		auto[width, height] = (std::pair<int, int>) texture.second.size->dimension;
		DrawTexture(texture.second, x + m_CellOffset.getX(), y + m_CellOffset.getY(), width, height);
	}
}

void Renderer::DrawTexture(const Texture& texture, int x, int y, int width, int height)
{
	SDL_Rect distrect{x, y, width, height};
	SDL_Rect* srcrect = texture.ComputeActualSrcRect();
	SDL_RenderCopy(m_Renderer, texture.texture, srcrect, &distrect);
}

void Renderer::ProjectPositionAndSize(Position<int>& position, Dimension<int>& size)
{
	auto&[x, y] = position.position;
	auto&[width, height] = size.dimension;
	x -= m_CellOffset.getX();
	y -= m_CellOffset.getY();
	width = std::ceil(width * m_RenderCellSize.getWidth() / Map::Width());
	height = std::ceil(height * m_RenderCellSize.getHeight() / Map::Height());
}
