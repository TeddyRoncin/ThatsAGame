#include "pch.h"

#include "inputs/WindowsInput.h"

void WindowsInput::Update(SDL_Event e)
{
    switch(e.type)
    {
    case SDL_WINDOWEVENT_MOVED:
        m_coord.x = e.window.data1;
        m_coord.x = e.window.data2;
        break;
    case SDL_WINDOWEVENT_SIZE_CHANGED: //both have the same effect
    case SDL_WINDOWEVENT_RESIZED:
        m_size.x = e.window.data1;
        m_size.x = e.window.data2;
        break;
    case SDL_WINDOWEVENT_ENTER:
        isMouseIn = true;
        break;
    case SDL_WINDOWEVENT_LEAVE:
        isMouseIn = false;
        break;
    case SDL_WINDOWEVENT_SHOWN:
    case SDL_WINDOWEVENT_HIDDEN:
    case SDL_WINDOWEVENT_MINIMIZED:
    case SDL_WINDOWEVENT_MAXIMIZED:
    case SDL_WINDOWEVENT_RESTORED:
    case SDL_WINDOWEVENT_FOCUS_GAINED:
    case SDL_WINDOWEVENT_FOCUS_LOST:
    case SDL_WINDOWEVENT_CLOSE:
    case SDL_WINDOWEVENT_TAKE_FOCUS:
    case SDL_WINDOWEVENT_HIT_TEST:
        break; //this is ugly but if we need that we'll see later about that
    default:
        std::cerr << "Window event unandled : " << e.type << std::endl;
        break;
    }

    std::unique_ptr<Event> event{new WindowsEvent{e}};
    EventHandler::addEvent(std::move(event));
}

Coordinates WindowsInput::getCoord() const
{
    return m_coord;
}

Coordinates WindowsInput::getSize() const
{
    return m_size;
}

bool WindowsInput::isMouseInside() const
{
    return isMouseIn;
}

WindowsEvent::WindowsEvent(SDL_Event e)
{
    m_type = Et::WindowsEvent;
    event = e.window;
}