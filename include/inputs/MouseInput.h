#pragma once

#include <map>
#include "SDL2/SDL.h"
#include "EventDispatcher.h"

class MouseInput
{
public:
    void Update(SDL_Event e);

    bool isDown(int key) const;
private:
    std::map<int, bool> m_isButtonDown;
    Coordinates coord;
};

class MouseMotionEvent : public Event 
{
public:
    MouseMotionEvent(SDL_Event e);
    virtual ~MouseMotionEvent() = default;
    SDL_MouseMotionEvent event;
};

class MouseButtonEvent : public Event 
{
public:
    MouseButtonEvent(SDL_Event e);
    virtual ~MouseButtonEvent() = default;
    SDL_MouseButtonEvent event;
};

class MouseWheelEvent : public Event 
{
public:
    MouseWheelEvent(SDL_Event e);
    virtual ~MouseWheelEvent() = default;
    SDL_MouseWheelEvent event;
};