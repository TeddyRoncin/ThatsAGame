#pragma once

#include "EventBinding.h"
#include "test_folder/renderer/Window.h"

class EventListener : public virtual EventBinding
{
    friend void Window::Render() const;
public:
    Action m_Action;

public:
    virtual void handle() =0;
    inline virtual void UpdateData(SDL_Event& event) {
        m_Action = Action::None;
        if(event.type == SDL_EventType::SDL_KEYDOWN)
        {
            m_Action = EventBinding::GetAction(static_cast<SDL_KeyCode>(event.key.keysym.sym));
        } else if(event.type == SDL_EventType::SDL_MOUSEBUTTONDOWN) {
            m_Action = EventBinding::GetAction(static_cast<int>(event.button.button));
        }
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
