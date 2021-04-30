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
const Uint8* EventListener::keyPressed = nullptr;

EventListener::~EventListener()
{
	listeners.erase(std::find(listeners.begin(), listeners.end(), this));
}

void EventListener::UpdateData(SDL_Event& event) {
	m_CurrentEvent = &event; // ?
	m_Action = Action::None;
	switch (event.type)
	{
		case SDL_EventType::SDL_KEYDOWN: m_Action = EventBinding::GetAction((SDL_KeyCode) event.key.keysym.sym); break;
		// case SDL_EventType::SDL_MOUSEBUTTONDOWN: m_Action = EventBinding::GetAction(event.button.button); break;
	}
}

bool EventListener::GetKeyState(SDL_Scancode scancode)
{
	return keyPressed[scancode];
}

void EventListener::Update()
{
	while (SDL_PollEvent(&m_Event))
	{
		if (m_Event.type == SDL_EventType::SDL_KEYDOWN || m_Event.type == SDL_EventType::SDL_KEYUP)
		{
			continue;
		}
		for (EventListener* listener : listeners)
		{
			listener->UpdateData(m_Event);
			listener->handle();
		}
	}
	int length;
	keyPressed = SDL_GetKeyboardState(&length);
	for (int i = 0; i < length; i++)
	{
		if(EventBinding::GetAction(SDL_GetKeyFromScancode((SDL_Scancode) i)) && keyPressed[i]) {
			SDL_Event event;
			event.type = SDL_EventType::SDL_KEYDOWN;
			event.key.keysym.sym = SDL_GetKeyFromScancode((SDL_Scancode) i);
			for (EventListener* listener : listeners)
			{
				listener->UpdateData(event);
				listener->handle();
			}
		}
	}
}
