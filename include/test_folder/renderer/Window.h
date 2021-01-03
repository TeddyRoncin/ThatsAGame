#pragma once

#include "test_folder/renderer/Renderer.h"

class Window
{
public:
    Window(ApplicationState* state, Map* map = nullptr);
    void AddMap(const Map* map);
    bool IsFullScreen() const;
    void SetFullScreen(bool fullScreen) const;
    void Render() const;

private:
    Renderer m_Renderer;
    Dimension<int> m_Size;
};