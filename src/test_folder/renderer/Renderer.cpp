#include "pch.h"

#include "test_folder/renderer/Renderer.h"
#include "test_folder/EnTT.h"
#include "test_folder/renderer/Texture.h"

Renderer::Renderer(ApplicationState* state, Map& map)
    : mState(state), mMap(map)
{
}

void Renderer::Render()
{
    switch (*mState) {
        case ApplicationState::HOME: RenderHome();
        case ApplicationState::GAME: RenderGame();
    }
}

void Renderer::RenderHome()
{
}

void Renderer::RenderGame()
{
    std::vector<Entity*> entities = mMap.getEntities();
    std::sort(entities.begin(), entities.end(), [](Entity entity1, Entity entity2) { return entity1.getZ() > entity2.getZ(); });
    for (Entity* entity : entities) {
        Texture texture = entity->getTexture();
        // TODO : display the texture on the window at texture.computeActualPosition() with size texture.computeActualSize()
    }
}
