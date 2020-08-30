#include "MouseInput.h"

void MouseInput::Update(SDL_Event e)
{
    switch(e.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        m_isKeyDown.at(e.key.keysym.sym) = true;
        break;
    case SDL_MOUSEBUTTONUP:
        m_isKeyDown.at(e.key.keysym.sym) = false;
        break;
    case SDL_MOUSEMOTION:
        coor.x = e.key.x;
        coord.y = e.key.y;
        break;
    default:
        fprintf(stderr, "Mouse event unandled : " + events.type);
        break;
    }
}

virtual MouseMotionEvent::MouseMotionEvent(SDL_Event e)
{
    m_type = MouseMotionEvent;
    event = e.motion;
}

virtual MouseButtonEvent(SDL_Event e)
{
    m_type = MouseButtonEvent;
    event = e.button;
}

virtual MouseWheelEvent(SDL_Event e)
{
    m_type = MouseWheelEvent;
    event = e.wheel;
}