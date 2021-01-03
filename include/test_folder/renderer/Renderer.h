#pragma once

#include "test_folder/application/ApplicationState.h"
#include "map/Map.h"

class Renderer
{

public:
    Renderer(ApplicationState* state, Map& map);
    void Render();

private:
    void RenderHome();
    void RenderGame();

private:
    const ApplicationState* const mState;
    const Map mMap;

};