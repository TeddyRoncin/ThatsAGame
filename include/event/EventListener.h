#pragma once

#include "EventBinding.h"

class Application;

class EventListener : public virtual EventBinding
{
	friend Application;
public:
	// Action m_Action;

public:
	virtual void handle() =0;
	virtual void UpdateData(SDL_Event& event);

private:
	static SDL_Event m_Event;
	static std::vector<EventListener*> listeners;

private:
	static void Update();

protected:
	EventListener(EventListener* listener);
	virtual ~EventListener();
	Action m_Action;
	SDL_Event* m_CurrentEvent;
};
