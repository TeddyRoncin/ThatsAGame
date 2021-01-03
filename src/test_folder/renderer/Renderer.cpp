#include "pch.h"

#include "test_folder/renderer/Renderer.h"
#include "test_folder/entity/Entity.h"
#include "test_folder/renderer/Texture.h"

Renderer::Renderer(const ApplicationState* const state, SDL_Window* window, const Map* map)
    : m_State(state), m_Map(map), m_WindowSize(0, 0)
{
    m_Renderer = SDL_CreateRenderer(window,-1,0);
	if(!m_Renderer)
	{
		std::cerr << "SDL_CreateRendererError: " << SDL_GetError() << std::endl;
	}
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

void Renderer::Render() const
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

void Renderer::RenderHome() const
{
}

void Renderer::RenderGame() const
{
    if (m_Map == nullptr)
    {
        return;
    }
    std::vector<RenderableEntity*> entities = m_Map->getEntities();
    std::sort(entities.begin(), entities.end(), [](Entity entity1, Entity entity2) { return entity1.getZ() > entity2.getZ(); });
    for (Entity* entity : entities) {
        Texture texture = entity->getTexture();
        SDL_Texture* sdlTexture = IMG_LoadTexture(m_Renderer, texture.texturePath);
        auto[x, y] = texture.ComputeActualPosition({m_Map->Width(), m_Map->Height()}, {m_WindowSize.getWidth(), m_WindowSize.getHeight()}).getPosition();
        auto[width, height] = texture.ComputeActualSize({m_Map->Width(), m_Map->Height()}, {m_WindowSize.getWidth(), m_WindowSize.getHeight()}).getDimension();
        SDL_Rect dest = {x, y, width, height};
        SDL_RenderCopy(m_Renderer, sdlTexture, nullptr, &dest);
    }
}
