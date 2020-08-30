#pragma once

#include <memory>
#include <stack>

namespace Et //for escaping the redefinition of KeyboardEvent
{
    enum EventType
    {
        WindowsEvent,
        MouseMotionEvent,
        MouseWheelEvent,
        MouseButtonEvent,
        KeyboardEvent
    };
}

class Event
{
public:
    Event();
    virtual ~Event() = 0;

    Et::EventType getEventType() const;
protected:
    Et::EventType m_type;
};
class EventHandler
{
public:
    static void addEvent(std::unique_ptr<Event> ptr);

    static std::unique_ptr<Event> nextEvent();

private:
    static std::stack<std::unique_ptr<Event>> m_listEvents;
};

struct Coordinates
{
    int x;
    int y;
};
