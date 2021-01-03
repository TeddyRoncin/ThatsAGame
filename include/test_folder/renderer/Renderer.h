#pragma once

#include "test_folder/application/ApplicationState.h"
#include "map/Map.h"

class Renderer
{

public:
    Renderer(const ApplicationState* const state, const Map* map = nullptr);
    void AddMap(const Map* map);
    void Render() const;

private:
    void RenderHome() const;
    void RenderGame() const;

private:
    const ApplicationState* const m_State;
    const Map* m_Map;

};