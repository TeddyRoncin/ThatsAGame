#include "inputs/EventDispatcher.h"

Event::Event() {}

Et::EventType Event::getEventType() const
{
    return m_type;
}

static void addEvent(std::unique_ptr<Event> ptr)
{
    
}