#include "pch.h"

#include "test_folder/renderer/Renderer.h"
#include "test_folder/entity/RenderableEntity.h"
#include "test_folder/renderer/Texture.h"

Renderer::Renderer(const ApplicationState* const state, const Map* map)
    : m_State(state), m_Map(map)
{
}

void Renderer::AddMap(const Map* map)
{
    m_Map = map;
}

void Renderer::Render() const
{
    switch (*m_State) {
        case ApplicationState::Home: RenderHome(); break;
        case ApplicationState::Game: RenderGame(); break;
        default: std::cerr << "Unknow application state : " << *m_State << ". Skipping render for this frame" << std::endl;
    }
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
        // TODO : display the texture on the window at texture.computeActualPosition() with size texture.computeActualSize()
    }
}
