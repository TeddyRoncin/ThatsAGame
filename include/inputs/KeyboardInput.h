#pragma once

#include "SDL2/SDL.h"
#include "EventDispatcher.h"

class KeyboardInput //can be access at anytime, exist once
{
public:
    KeyboardInput() = default;
    ~KeyboardInput() = default;

    void Update(SDL_Event e);

    bool isDown(int key);
    //can't be const cause we add a button if you try it but is has never been push down before

    bool isBeeingPushDown() const;
    bool isBeeingPushUp() const;
    int keyBeeingPush() const;
private:
    std::map<int, bool> m_isKeyDown;

    bool isPushDown;
    bool isPushUp;
    int key;
};

class KeyboardEvent : public Event //just for the event handler
{
public:
    KeyboardEvent(SDL_Event e);
    virtual ~KeyboardEvent() = default;

    SDL_KeyboardEvent event;
};