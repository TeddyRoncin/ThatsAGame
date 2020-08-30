#include "inputs/EventDispatcher.h"

Event::Event() {}

<<<<<<< HEAD
#include "inputs/EventDispatcher.h"

Event::Event() {}

=======
>>>>>>> debug and delete map folder to simplify the merge
Et::EventType Event::getEventType() const
{
    return m_type;
}

<<<<<<< HEAD
<<<<<<< HEAD
std::deque<std::unique_ptr<Event>> EventHandler::m_listEvents {};

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

=======
EventHandler::EventHandler()
{
}
>>>>>>> commit debugging
=======
static void addEvent(std::unique_ptr<Event> ptr)
{
    
}
>>>>>>> debug and delete map folder to simplify the merge
