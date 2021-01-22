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
    Quit();
}

void Window::SetSize(Dimension<int> newSize)
{
    m_Size = newSize;
    m_Renderer.SetWindowSize(newSize);
}

bool Window::IsFullScreen() const
{
    // TODO : return true if fullscreen, else false
    SDL_DisplayMode mode;
}

void Window::SetFullScreen(bool fullScreen) const
{
    // TODO : set window fullscreen if fullScreen is true, else un-fullscreen window
}

void Window::Render()
{
    m_Renderer.Render();
    EventListener::Update();
}

void Window::Quit()
{
    m_Renderer.~Renderer();
    SDL_DestroyWindow(m_Window);
}
