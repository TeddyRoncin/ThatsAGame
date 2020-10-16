#pragma once

#include "inputs/Inputs.h"

class EventHandler
{
public:
	void flushEvents();
private:
	SDL_Event m_Events;
	Input input;
};
