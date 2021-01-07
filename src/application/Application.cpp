#include "pch.h"

#include "application/Application.h"
#include "utils/Timer.h"

Application::Application()
	: Context(SDL_INIT_EVERYTHING), EventListener(this), m_Window(&m_CurrentState, &map), m_CurrentState(ApplicationState::Game), map(), m_Running(true)
{
}

void Application::handle()
{
	if(m_Action == Action::OpenMenu) {
		std::cout << "Open Menu" << std::endl;
	}
	if(m_Action == Action::Quit) {
		m_Running = false;
	}
	switch (m_CurrentEvent->type)
	{
		case SDL_EventType::SDL_QUIT:
			m_Window.Quit();
			m_Running = false;
			return;
		case SDL_EventType::SDL_WINDOWEVENT:
			if (m_CurrentEvent->window.type == SDL_WINDOWEVENT_RESIZED) {
				std::cout << "boujour !" << std::endl;
				m_Window.SetSize({m_CurrentEvent->window.data1, m_CurrentEvent->window.data2});
				return;
			}
	}
}

void Application::loop()
{
	Timer timer;
	while (m_Running)
	{
		m_Window.Render();
		//std::cout << timer.getFps() << std::endl;
		timer.waitForNextFrame();
	}
}
