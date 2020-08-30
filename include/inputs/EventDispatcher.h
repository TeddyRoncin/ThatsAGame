#pragma once

#include <memory>

struct EventType
{
    WindowsEvent,
    MouseMotionEvent,
    MouseWheelEvent,
    MouseButtonEvent,
    KeyboardEvent
};

class Event
{
public:
    Event();
    virtual ~Event() = 0;

    EventType getEventType() const;
private:
    EventType m_type;
};




class EventHandler
{
public:
    EventHandler(std::size_t size = 10);
    void addEvent(std::unique_ptr<Event> ptr);

    std::unique_ptr<Event> nextEvent();

private:
    std::stack<std::unique_ptr<Event>> m_listEvents;
};
