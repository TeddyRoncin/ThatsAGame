#pragma once

#include "test_folder/application/ApplicationState.h"
#include "map/Map.h"

class Renderer
{

public:
    Renderer(const ApplicationState* const state, SDL_Window* window, const Map* map = nullptr);
    ~Renderer();
    Renderer operator=(const Renderer& renderer);
    void SetWindowSize(Dimension<int> newSize);
    void AddMap(const Map* map);
    void Render() const;

private:
    void RenderHome() const;
    void RenderGame() const;

private:
    const ApplicationState* const m_State;
    const Map* m_Map;
    SDL_Renderer* m_Renderer;
    Dimension<int> m_WindowSize;
};