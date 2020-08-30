#pragma once

#include <cstdio>
#include <string>
#include <stack>
#include <utility>

#include "MouseInput.h"
#include "KeyboardInput.h"
#include "WindowsInput.h"

#include "SDL2/SDL.h"

struct Coordinates
{
    Uint16 x;
    Unit16 y;
}

class Input
{
public:
    Input();

    void eventUpdate(SDL_Event events); //where events are updated

    bool isQuitting();
private:
    KeyboardInput m_keys;
    MouseInput m_mouse;
    WindowsInput m_window;

    bool m_quit;
};

struct EventType
{
    WindowsEvent,
    MouseMotionEvent,
    MouseWheelEvent,
    MouseButtonEvent,
    KeyboardEvent
}

class Event
{
public:
    virtual Event() = 0;

    EventType getEventType() const;
private:
    EventType m_type;
};

class EventHandler
{
public:
    EventHandler(std::size_t size);
    void addEvent(std::unique_ptr<Event> ptr);

    std::unique_ptr<Event> nextEvent();

private:
    std::stack<std::unique_ptr<Event>> m_listEvents;
}