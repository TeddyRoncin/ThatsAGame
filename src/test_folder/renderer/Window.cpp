#include "pch.h"
#include "test_folder/renderer/Window.h"

#include "event/EventListener.h"

Window::Window(ApplicationState* state, Map* map)
    : m_Renderer(state, map), m_Size(500, 500)
{
}

void Window::AddMap(const Map* map)
{
    m_Renderer.AddMap(map);
}

bool Window::IsFullScreen()
{
    // TODO : return true if fullscreen, else false
}

void Window::SetFullScreen(bool fullScreen)
{
    // TODO : set window fullscreen if fullScreen is true, else un-fullscreen window
}

void Window::Render()
{
    m_Renderer.Render();
    EventListener::Update();
}
