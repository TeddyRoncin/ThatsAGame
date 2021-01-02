#include "pch.h"

#include "event/EventListener.h"
#include "event/EventBinding.h"

EventListener::EventListener(EventListener* listener)
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
