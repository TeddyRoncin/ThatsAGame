#include "Inputs/Inputs.h"

Input::Input()
     : m_quit(false), m_keys(), m_mouse()
{
}

void Input::eventUpdate(SDL_Event events)
{
    while( SDL_PollEvent(&events))
    {
        switch(events.type)
        {
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                m_keys.Update(events);
                break;
            case SDL_MOUSEMOTION:
            case SDL_MOUSEWHEEL:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                m_mouse.Update(events);
                break;
            case SDL_WINDOWEVENT:
                m_window.Update(events);
                break;
            case SDL_QUIT:
                m_quit = true;
                break;
            default:
                fprintf(stderr, "Event unandled : " + events.type);
                break;
        }
    }
}

bool Input::isQuitting()
{
    return m_quit;
}

EventType getEventType() const
{
    return m_type;
}