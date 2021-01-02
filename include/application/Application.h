#pragma once

#include "event/EventListener.h"

#include "map/Map.h"

/**
 * La Map charge des MapElements puis l'Application charge
 * les entitées dans un vector de Entity (ex: std::vector<Entity*> entities)
*/

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
