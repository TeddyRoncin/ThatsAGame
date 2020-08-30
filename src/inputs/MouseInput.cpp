#include "inputs/MouseInput.h"

void MouseInput::Update(SDL_Event e)
{
    std::unique_ptr<Event> event = nullptr;

    switch(e.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        m_isKeyDown.at(e.key.keysym.sym) = true;
        event = std::move<MouseMotionEvent>(new MouseMotionEvent{e.key});
        break;
    case SDL_MOUSEBUTTONUP:
        m_isKeyDown.at(e.key.keysym.sym) = false;
        event = std::move<MouseButtonEvent>(new MouseButtonEvent{e.key});
        break;
    case SDL_MOUSEMOTION:
        coor.x = e.key.x;
        coord.y = e.key.y;
        event = std::move<MouseWheelEvent>(new MouseWheelEvent{e.key});
        break;
    default:
        fprintf(stderr, "Mouse event unandled : " + events.type);
        break;
    }
}

MouseMotionEvent::MouseMotionEvent(SDL_Event e)
{
    m_type = MouseMotionEvent;
    event = e.motion;
}

MouseButtonEvent(SDL_Event e)
{
    m_type = MouseButtonEvent;
    event = e.button;
}

MouseWheelEvent(SDL_Event e)
{
    m_type = MouseWheelEvent;
    event = e.wheel;
}