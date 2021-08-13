#include "pch.h"

#include "application/Application.h"
#include "utils/Timer.h"
#include "ui/Text.h"
#include "entity/TestAnimable.h"
#include "ui/Button.h"
#include "ui/screen/ScreenManager.h"

Application::Application()
	: Context(SDL_INIT_EVERYTHING), EventListener(this), m_CurrentState(ApplicationState::Game), m_Window(&m_CurrentState), m_Map(), m_Running(true)
{
	ScreenManager::Init();
}

Application::~Application()
{
	ScreenManager::Destroy();
}

void Application::handle()
{
	switch (m_Action)
	{
		case Action::OpenMenu:
			std::cout << "Open Menu" << std::endl;
			break;
		case Action::Quit:
			m_Running = false;
			return;
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
		case SDL_EventType::SDL_USEREVENT:
			// refactor code in Map.cpp to create clean user event
			if(m_CurrentEvent->user.code == 100)
			{
				m_Window.SetSize(m_Window.GetSize());
			}
	}
}

void Application::loop()
{
	//Text text(Position<float>{0, 0}, Dimension<float>{100, 100}, "Hello World !", TTF_OpenFont("assets/font/arial/arial.ttf", 500));
	Timer::Init(60);
	ScreenManager::AddDemoScreen();
	while (m_Running)
	{
		EventListener::Update();
		m_Map.Tick();
		ScreenManager::Update();
		m_Window.Render();
		//text.SetText(std::to_string(Timer::getFps()));
		Timer::waitForNextFrame();
	}
}
