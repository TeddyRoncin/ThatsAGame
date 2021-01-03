#include "pch.h"

#include "application/Application.h"

/**
 * TODO: améliorer le renderer et peut être faire une \class Window
 * pour get la taille de la fenetre plutot que de les mettre en dure
 * comme ça !!!
*/

Application::Application()
	:EventListener(this), map()
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
		//UpdateListener();
	}
}
