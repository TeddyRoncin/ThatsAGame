#pragma once

#include "event/EventListener.h"

#include "map/Map.h"

class Application : public EventListener
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
