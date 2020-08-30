#pragma once

#include <iostream>

#include "SDL2/SDL.h"
#include "EventDispatcher.h"

class WindowsInput
{
public:
    void Update(SDL_Event e);
private:
    Coordinates m_coord;
    Coordinates m_size;
};

class WindowsEvent : public Event 
{
public:
    WindowsEvent(SDL_Event e);
    virtual ~WindowsEvent() = default;
    SDL_WindowEvent event;
};