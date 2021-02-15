#pragma once

#include "renderer/Context.h"
#include "event/EventListener.h"
#include "application/ApplicationState.h"
#include "renderer/Window.h"
#include "map/Map.h"

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
	Map m_Map;
	bool m_Running;
};
