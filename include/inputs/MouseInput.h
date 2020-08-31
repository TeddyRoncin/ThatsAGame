#pragma once

#include <map>
#include <iostream>
#include "SDL2/SDL.h"
#include "EventDispatcher.h"

class MouseInput
{
public:
    void Update(SDL_Event e);
    ~MouseInput();

    bool isDown(int key);
    //can't be const cause we add a button if you try it but is has never been push down before

    bool isBeeingPushDown() const;
    bool isBeeingPushUp() const;
    int keyBeeingPush() const;
private:
    std::map<int, bool> m_isButtonDown;
    Coordinates coord;

    bool isPushDown;
    bool isPushUp;
    int key;
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