#pragma once

#include "SDL2/SDL.h"

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
    virtual WindowsEvent(SDL_Event e);
    SDL_WindowEvent event;
};