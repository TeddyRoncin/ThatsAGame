#include "pch.h"
#include "test_folder/renderer/Window.h"

#include "event/EventListener.h"

Window::Window(ApplicationState* state, Map* map)
    :m_Size(500, 500), m_Window(SDL_CreateWindow("Render Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_Size.getWidth(), m_Size.getHeight(), SDL_WindowFlags::SDL_WINDOW_RESIZABLE)), m_Renderer(state, m_Window, map)
{
    if(!m_Window)
	{
		std::cerr << "SDL_CreateWindowError : " << SDL_GetError() << std::endl;
	}
    SetSize(m_Size);
}

Window::~Window()
{
    SDL_DestroyWindow(m_Window);
}

void Window::SetSize(Dimension<int> newSize)
{
    m_Size = newSize;
    m_Renderer.SetWindowSize(newSize);
}

void Window::AddMap(const Map* map)
{
    m_Renderer.AddMap(map);
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

void Window::Render() const
{
    m_Renderer.Render();
    EventListener::Update();
}
