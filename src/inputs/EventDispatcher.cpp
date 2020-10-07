#include "pch.h"
#include "inputs/EventDispatcher.h"

Event::Event() {}

Et::EventType Event::getEventType() const
{
    return m_type;
}

std::deque<std::unique_ptr<Event>> EventHandler::m_listEvents {};
bool EventHandler::m_isValid {true};

void EventHandler::addEvent(std::unique_ptr<Event> ptr)
{
    if(m_isValid)
    {
        m_listEvents.push_back(std::move(ptr));
    }
}

std::unique_ptr<Event> EventHandler::nextEvent()
{
    std::unique_ptr<Event> e {nullptr};
    if(m_isValid)
    {
        std::unique_ptr<Event> e {std::move(m_listEvents.front())};
        m_listEvents.pop_front();
    }
    return e;
}

void EventHandler::kill()
{
    std::cout << "Destroy !" << std::endl;
    m_listEvents.~deque<std::unique_ptr<Event>>(); 
    //destroy the deque, need to check if its exists anymore
    std::cout << "Destrefoy !" << std::endl;
    //m_listEvents.size();
}

void EventHandler::removeOld()
{
    if(m_isValid)
    {
        for(int i {100}; i < m_listEvents.size(); i++)
        {
            m_listEvents.pop_front();
        }
    }
}