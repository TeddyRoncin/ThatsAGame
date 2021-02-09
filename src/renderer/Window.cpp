#include "pch.h"

#include "renderer/Window.h"
#include "event/EventListener.h"

Window::Window(ApplicationState* state)
    : m_Size(500, 500),
    m_Window(SDL_CreateWindow("Render Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_Size.getWidth(), m_Size.getHeight(), SDL_WindowFlags::SDL_WINDOW_RESIZABLE)),
    m_Renderer(state, m_Window)
{
    if(!m_Window)
	{
		std::cerr << "SDL_CreateWindowError : " << SDL_GetError() << std::endl;
	}
    SetSize(m_Size);
}

Window::~Window()
{
    m_Renderer.~Renderer();
    SDL_DestroyWindow(m_Window);
}

void Window::SetSize(Dimension<int> newSize)
{
    m_Size = newSize;
    m_Renderer.SetWindowSize(newSize);
}

bool Window::IsFullScreen() const
{
    // TODO : verify the test
    return (SDL_GetWindowFlags(m_Window) & SDL_WINDOW_FULLSCREEN);
}

void Window::SetFullScreen(bool fullScreen) const
{
    // TODO : verify the trigger happends when we really intend to do it
    bool IsFullscreen = SDL_GetWindowFlags(m_Window) & SDL_WINDOW_FULLSCREEN;
    SDL_SetWindowFullscreen(m_Window, (IsFullscreen && fullScreen) ? 0 : SDL_WINDOW_FULLSCREEN);
    SDL_ShowCursor(IsFullscreen);
}

void Window::Render()
{
    m_Renderer.Render();
    EventListener::Update();
}
