#include "pch.h"

#include "renderer/Window.h"

Window::Window(const char* name)
	:m_Renderer(name), m_Running(true), test()
{
	m_Renderer.AddMap(test);
}

#define BIND_EVENT_FN(x) std::bind(&Window::x, this, std::placeholders::_1)
void Window::OnUpdate(Event& event)
{
	EventDispatcher dispatcher(event);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(CloseWindow));
}

void Window::Run()
{
	SDL_Event event;
	while(m_Running)
	{
		m_Renderer.UpdateRender();
		m_Renderer.Present();
	}
}

bool Window::CloseWindow(WindowCloseEvent& event)
{
	m_Running = false;
	return true;
}