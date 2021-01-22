#include "pch.h"

#include "renderer/Renderer.h"

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
    std::cout << newSize.getWidth() << std::endl;
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
    for(auto& textureinfo : textures) {
        auto[x, y] = textureinfo.second.ComputeActualPosition({30, 30}, m_WindowSize).getPosition();
        auto[width, height] = textureinfo.second.ComputeActualSize({30, 30}, m_WindowSize).getDimension();
        SDL_Rect distrect{x, y, width, height};
        SDL_RenderCopy(m_Renderer, textureinfo.second.texture, nullptr, &distrect);
    }
}
