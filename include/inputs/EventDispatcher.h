#pragma once
<<<<<<< HEAD
enum EventType
=======

#include <memory>
#include <stack>

namespace Et //for escaping the redefinition of KeyboardEvent
>>>>>>> debug and delete map folder to simplify the merge
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
    ~Event() = default;

    Et::EventType getEventType() const;
protected:
    Et::EventType m_type;
};

class EventHandler
{
public:

    static void addEvent(std::unique_ptr<Event> ptr);

    static std::unique_ptr<Event> nextEvent(); //note that using that will delete the event in the dispatcher. 
    //it will no longer be stockted 

private:
    static std::deque<std::unique_ptr<Event>> m_listEvents;
};

struct Coordinates //TODO faire un Union a partir de ca
{
    int x;
    int y;
};

struct Coordinates
{
    int x;
    int y;
};
