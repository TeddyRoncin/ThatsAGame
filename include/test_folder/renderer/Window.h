#pragma once

#include "test_folder/renderer/Renderer.h"

class Window
{
public:
    Window(ApplicationState* state, Map& map);
    bool IsFullScreen();
    void SetFullScreen(bool fullScreen);
    void Render();

private:
    Renderer m_Renderer;
    Dimension<int> m_Size;
};