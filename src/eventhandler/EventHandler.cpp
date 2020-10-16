#include "pch.h"
#include "eventhandler/EventHandler.h"

void EventHandler::flushEvents()
{
	SDL_PollEvent(&m_Events);
	input.eventUpdate(m_Events);
}
