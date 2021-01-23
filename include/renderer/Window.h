#pragma once

#include "renderer/Renderer.h"

class Window
{
public:
    Window(ApplicationState* state);
    ~Window();
    void SetSize(Dimension<int> newSize);
    bool IsFullScreen() const;
    void SetFullScreen(bool fullScreen) const;
    void Render();

private:
    Dimension<int> m_Size;
    SDL_Window* m_Window;
    Renderer m_Renderer;
};
