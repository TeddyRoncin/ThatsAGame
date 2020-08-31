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
    default:
        std::cerr << "Window event unandled : " << e.type << std::endl;
        break;
    }

    std::unique_ptr<Event> event{new WindowsEvent{e}};
    EventHandler::addEvent(std::move(event));
}

WindowsEvent::WindowsEvent(SDL_Event e)
{
    m_type = Et::WindowsEvent;
    event = e.window;
}