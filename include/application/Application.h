#pragma once

#include "event/EventListener.h"

#include "map/Map.h"

#include "test_folder/renderer/Context.h"
#include "application//ApplicationState.h"
#include "test_folder/renderer/Window.h"

class Application : public Context, public EventListener
{
public:
	Application();
public:
	virtual void handle() override;
public:
	void loop();
private:
	ApplicationState m_CurrentState;
	Window m_Window;
	Map map;
	bool m_Running;
};
