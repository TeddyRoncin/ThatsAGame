#include "pch.h"

#include "test_folder/renderer/Renderer.h"
#include "test_folder/entity/RenderableEntity.h"
#include "test_folder/renderer/Texture.h"

Renderer::Renderer(const ApplicationState* const state, SDL_Window* window, const Map* map)
    : m_State(state), m_WindowSize(0, 0), m_Renderer(SDL_CreateRenderer(window,-1,0))
{
    m_Map = map;
	if(!m_Renderer)
	{
		std::cerr << "SDL_CreateRendererError: " << SDL_GetError() << std::endl;
	}
    TextureManager::Init(m_Renderer);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(m_Renderer);
}

Renderer Renderer::operator=(const Renderer& renderer)
{
    return renderer;
}

void Renderer::SetWindowSize(Dimension<int> newSize)
{
    m_WindowSize = newSize;
}

void Renderer::AddMap(const Map* map)
{
    m_Map = map;
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
    if (m_Map == nullptr)
    {
        return;
    }
    std::vector<MapElement*> entities = m_Map->GetEntities();
    std::sort(entities.begin(), entities.end(), [](RenderableEntity* entity1, RenderableEntity* entity2) { return entity1->GetRenderPriorityLevel() > entity2->GetRenderPriorityLevel(); });
    for (RenderableEntity* entity : entities) {
        Texture& texture = entity->GetTexture();
        //std::cout << texture.texturePath << std::endl;
        SDL_Texture* sdlTexture = TextureManager::GetTexture(texture.texturePath);
        auto[x, y] = texture.ComputeActualPosition({m_Map->Width(), m_Map->Height()}, {m_WindowSize.getWidth(), m_WindowSize.getHeight()}).getPosition();
        auto[width, height] = texture.ComputeActualSize({m_Map->Width(), m_Map->Height()}, {m_WindowSize.getWidth(), m_WindowSize.getHeight()}).getDimension();
        SDL_Rect dest = {x, y, width, height};
        SDL_RenderCopy(m_Renderer, sdlTexture, nullptr, &dest);
    }
    SDL_RenderPresent(m_Renderer);
}
