#include "pch.h"

#include "application/Application.h"
#include "utils/Timer.h"
#include "ui/Text.h"
<<<<<<< HEAD
#include "entity/TestAnimable.h"
=======
#include "ui/Button.h"
>>>>>>> 648b2cebfb055d5a025eae5fa90d36a0aafca069

Application::Application()
	: Context(SDL_INIT_EVERYTHING), EventListener(this), m_Window(&m_CurrentState), m_CurrentState(ApplicationState::Game), m_Map(), m_Running(true)
{
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
	}
}

/**
 * struct SpriteSheetInfo
{
	int currentFrame;
	int xoffset, yoffset;
	int currentIndex;
	std::map<std::string, std::vector<int>> animationList;

	SpriteSheetInfo addAnimation(std::string name, std::vector<int> indicies);
};
*/

void Application::loop()
{
	Position<int> position{0, 0};
	Dimension<int> size{100, 30};
	//Text text(Position<int>{0, 0}, Dimension<int>{100, 30}, "Hello World !", TTF_OpenFont("assets/font/arial/arial.ttf", 24));
	Button button(position, size, SDL_BUTTON_LMASK);
	Timer::Init(60);
	while (m_Running)
	{
		EventListener::Update();
		m_Map.Tick();
		m_Window.Render();
		//text.SetText(std::to_string(Timer::getFps()));
		Timer::waitForNextFrame();
	}
}
