#include "pch.h"

#include "event/EventListener.h"
#include "event/EventBinding.h"

EventListener::EventListener(EventListener* listener)
	: m_Action(Action::None), m_CurrentEvent(nullptr)
{
	memset(listener, Action::None, sizeof(Action));
	listeners.push_back(listener);
}

SDL_Event EventListener::m_Event;
std::vector<EventListener*> EventListener::listeners;

EventListener::~EventListener()
{
	for(EventListener* listener : listeners)
	{
		listener = nullptr;
	}
	listeners.clear();
}

void EventListener::UpdateData(SDL_Event& event) {
	m_CurrentEvent = &event;
	m_Action = Action::None;
	switch (event.type)
	{
		case SDL_EventType::SDL_KEYDOWN: m_Action = EventBinding::GetAction((SDL_KeyCode) event.key.keysym.sym); break;
		// case SDL_EventType::SDL_MOUSEBUTTONDOWN: m_Action = EventBinding::GetAction(event.button.button); break;
	}
}

void EventListener::Update()
{
	while (SDL_PollEvent(&m_Event))
	{
		for (EventListener* listener : listeners)
		{
			listener->UpdateData(m_Event);
			listener->handle();
		}
	}
}
