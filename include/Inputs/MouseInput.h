#pragma once

#include <map>
#include "SDL2/SDL.h"

class MouseInput
{
public:
    void Update(SDL_Event e);
private:
    std::map<int, bool> m_mouseEvnt;
    Coordinates coord;
};

class MouseMotionEvent : public Event 
{
public:
    virtual MouseMotionEvent(SDL_Event e);
    SDL_MouseMotionEvent event;
};

class MouseButtonEvent : public Event 
{
public:
    virtual MouseButtonEvent(SDL_Event e);
    SDL_MouseButtonEvent event;
};

class MouseWheelEvent : public Event 
{
public:
    virtual MouseWheelEvent(SDL_Event e);
    SDL_MouseWheelEvent event;
};