#include "pch.h"

#include "application/Application.h"
#include "entity/player/Player.h"

Application::Application()
	:EventListener(this), Renderer(), map()
{
	AddMap(map);
}

void Application::handle()
{
	if(m_Action == Action::OpenMenu) {
		std::cout << "Open Menu" << std::endl;
	}
}

void Application::loop()
{
	player p("assets/img/player.png", 400.0f, 400.0f, 200.0f, 200.0f);
	while(m_Action != Action::Quit)
	{
		UpdateListener();
		UpdateRender();
		RenderPlayer(p);
		Present();
	}
}
