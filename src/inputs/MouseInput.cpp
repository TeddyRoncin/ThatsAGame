#include "inputs/MouseInput.h"

void MouseInput::Update(SDL_Event e)
{
    switch(e.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        m_isButtonDown.at(e.key.keysym.sym) = true;
        std::unique_ptr<Event> event{e};
        EventHandler::addEvent(e);
        break;
    case SDL_MOUSEBUTTONUP:
        m_isButtonDown.at(e.key.keysym.sym) = false;
        std::unique_ptr<Event> event{e};
        EventHandler::addEvent(e);
        break;
    case SDL_MOUSEMOTION:
        coor.x = e.key.x;
        coord.y = e.key.y;
        std::unique_ptr<Event> event{e};
        EventHandler::addEvent(e);
        break;
    default:
        fprintf(stderr, "Mouse event unandled : " + events.type);
        break;
    }


}

bool MouseInput::isDown(int key) const
{
    return m_isKeyDown.at(key);
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