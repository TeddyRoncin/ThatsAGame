#include "inputs/EventDispatcher.h"

Event::Event() {}

EventType Event::getEventType() const
{
    return m_type;
}

EventHandler::EventHandler()
{
}