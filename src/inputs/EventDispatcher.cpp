#include "inputs/EventDispatcher.h"

Event::Event() {}

Et::EventType Event::getEventType() const
{
    return m_type;
}

void EventHandler::addEvent(std::unique_ptr<Event> ptr)
{
    m_listEvents.push_back(std::move(ptr));
}

std::unique_ptr<Event> EventHandler::nextEvent()
{
    std::unique_ptr<Event> e {std::move(m_listEvents.front())};
    m_listEvents.pop_front();
    return e;
}
