#pragma once

#include "EventBinding.h"

class EventListener : public virtual EventBinding
{
    friend void UpdateListener();
public:
    Action m_Action;

public:
    virtual void handle() =0;
    inline virtual void UpdateData(SDL_Event& event) {
        m_Action = EventBinding::GetAction(static_cast<SDL_KeyCode>(event.key.keysym.sym));
    }

private:
    static SDL_Event m_Event;
    static std::vector<EventListener*> listeners;

private:
    static void Update();

protected:
    EventListener(EventListener* listener);
    virtual ~EventListener();
};

void UpdateListener();