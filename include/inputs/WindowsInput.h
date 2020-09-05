#pragma once

#include "EventDispatcher.h"

class WindowsInput
{
public:
    void Update(SDL_Event e);

    Coordinates getCoord() const;
    Coordinates getSize() const;

    bool isMouseInside() const;
private:
    Coordinates m_coord;
    Coordinates m_size;

    bool isMouseIn;
};

class WindowsEvent : public Event 
{
public:
    WindowsEvent(SDL_Event e);
    virtual ~WindowsEvent() = default;
    SDL_WindowEvent event;
};