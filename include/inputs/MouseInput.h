#pragma once

#include <map>
#include "SDL2/SDL.h"
#include "EventDispatcher.h"

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
    MouseMotionEvent(SDL_Event e);
    virtual KeyboardEvent() = default;
    SDL_MouseMotionEvent event;
};

class MouseButtonEvent : public Event 
{
public:
    MouseButtonEvent(SDL_Event e);
    virtual KeyboardEvent() = default;
    SDL_MouseButtonEvent event;
};

class MouseWheelEvent : public Event 
{
public:
    MouseWheelEvent(SDL_Event e);
    virtual KeyboardEvent() = default;
    SDL_MouseWheelEvent event;
};