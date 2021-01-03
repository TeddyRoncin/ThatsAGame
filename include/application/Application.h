#pragma once

#include "event/EventListener.h"

#include "map/Map.h"

#include "test_folder/renderer/Context.h"
#include "test_folder/application/ApplicationState.h"
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
	Map map;
	ApplicationState m_CurrentState;
	Window m_Window;
};
