#include "pch.h"

#include "application/Application.h"
#include "utils/Timer.h"

Application::Application()
	: Context(SDL_INIT_EVERYTHING), EventListener(this), m_Window(&m_CurrentState), m_CurrentState(ApplicationState::Game), map(), m_Running(true)
{
}

void Application::handle()
{

	switch (m_Action)
	{
		case Action::OpenMenu:
			std::cout << "Open Menu" << std::endl;
		case Action::Quit:
			m_Running = false;
	}
	if(m_Action == Action::Quit) {
		m_Running = false;
	}
	switch (m_CurrentEvent->type)
	{
		case SDL_EventType::SDL_QUIT:
			m_Running = false;
			return;
		case SDL_EventType::SDL_WINDOWEVENT:
			if (m_CurrentEvent->window.event == SDL_WINDOWEVENT_RESIZED) {
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
