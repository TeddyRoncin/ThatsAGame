#include "pch.h"

#include "test_folder/renderer/Window.h"

#include "event/EventListener.h"

Window::Window(ApplicationState* state, Map& map)
    : mRenderer(state, map)
{
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
    mRenderer.Render();
    EventListener::Update();
}
