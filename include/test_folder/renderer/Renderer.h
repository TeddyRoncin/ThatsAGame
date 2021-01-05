#pragma once

#include "test_folder/application/ApplicationState.h"
#include "map/Map.h"
#include "test_folder/renderer/TextureManager.h"

class Renderer
{

public:
    Renderer(const ApplicationState* const state, SDL_Window* window, const Map* map = nullptr);
    ~Renderer();
    Renderer operator=(const Renderer& renderer);
    void SetWindowSize(Dimension<int> newSize);
    void AddMap(const Map* map);
    void Render();

private:
    void RenderHome();
    void RenderGame();
    template<typename T, typename std::enable_if<std::is_base_of<RenderableEntity, T>::value>::type* = nullptr>
    void RenderEntities(std::vector<T*> entities);

private:
    const ApplicationState* const m_State;
    SDL_Renderer* m_Renderer;
    const Map* m_Map;
    Dimension<int> m_WindowSize;
};