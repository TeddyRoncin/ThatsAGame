#include "../../include/inputs/EventDispatcher.h"

EventType Event::getEventType() const
{
    return m_type;
}

EventHandler::EventHandler(std::size_t size)
{
    m_listEvents.reserve(size);
}