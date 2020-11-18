#pragma once

#include "renderer/Renderer.h"
#include "event/EventListener.h"

#include "map/Map.h"

class Application : public EventListener, protected Renderer
{
public:
	Application();
public:
	virtual void handle() override;
public:
	void loop();
private:
	Map map;
};
