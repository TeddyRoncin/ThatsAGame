#include "inputs/MouseInput.h"

void MouseInput::Update(SDL_Event e)
{
    std::unique_ptr<Event> event;
    switch(e.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        {
            m_isButtonDown.at(e.button.state) = true;
            std::unique_ptr<Event> event{ new MouseButtonEvent{e} };
            EventHandler::addEvent(std::move(event));
        }
        break;
    case SDL_MOUSEBUTTONUP:
        {
            m_isButtonDown.at(e.button.state) = false;
            std::unique_ptr<Event> event{ new MouseButtonEvent{e}};
            EventHandler::addEvent(std::move(event));
        }
        break;
    case SDL_MOUSEMOTION:
        {
            coord.x = e.motion.x;
            coord.y = e.motion.y;
            std::unique_ptr<Event> event{new MouseMotionEvent{e}};
            EventHandler::addEvent(std::move(event));
        }
        break;
    case SDL_MOUSEWHEEL:
        {
            std::unique_ptr<Event> event{new MouseWheelEvent{e}};
            EventHandler::addEvent(std::move(event));
        }
        break;
    default:
        fprintf(stderr, "Mouse event unandled : " + e.type);
        break;
    }


}

bool MouseInput::isDown(int key) const
{
    return m_isButtonDown.at(key);
}

MouseMotionEvent::MouseMotionEvent(SDL_Event e)
{
    m_type = Et::MouseMotionEvent;
    event = e.motion;
}

MouseButtonEvent::MouseButtonEvent(SDL_Event e)
{
    m_type = Et::MouseButtonEvent;
    event = e.button;
}

MouseWheelEvent::MouseWheelEvent(SDL_Event e)
{
    m_type = Et::MouseWheelEvent;
    event = e.wheel;
}