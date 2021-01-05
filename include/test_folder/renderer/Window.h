#pragma once

#include "test_folder/renderer/Renderer.h"

class Window : public EventListener
{
public:
    Window(ApplicationState* state, Map* map = nullptr);
    ~Window();
    void SetSize(Dimension<int> newSize);
    void AddMap(const Map* map);
    bool IsFullScreen() const;
    void SetFullScreen(bool fullScreen) const;
    void Render() const;
    virtual void handle();

private:
    Dimension<int> m_Size;
    SDL_Window* m_Window;
    Renderer m_Renderer;
};