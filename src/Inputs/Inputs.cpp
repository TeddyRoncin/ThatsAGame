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

                break;
            case SDL_MOUSEMOTION:

                break;
            case SDL_MOUSEWHEEL:

                break;
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:

                break;
            case SDL_WINDOWEVENT:

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