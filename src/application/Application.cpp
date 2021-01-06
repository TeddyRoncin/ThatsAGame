#include "pch.h"

#include "application/Application.h"

Application::Application()
	:Context(SDL_INIT_EVERYTHING), EventListener(this), m_Window(&m_CurrentState, &map), m_CurrentState(ApplicationState::Game), map()
{
}

void Application::handle()
{
	if(m_Action == Action::OpenMenu) {
		std::cout << "Open Menu" << std::endl;
	}
}

void Application::loop()
{
	while(m_Action != Action::Quit)
	{
		m_Window.Render();
	}
}
