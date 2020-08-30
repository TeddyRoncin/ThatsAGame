#pragma once

#include <map>
#include "SDL2/SDL.h"
#include "EventDispatcher.h"

class KeyboardInput //can be access at anytime, exist once
{
public:
    KeyboardInput() = default;

    void Update(SDL_Event e);

    bool isDown(int key) const;
private:
    std::map<int, bool> m_isKeyDown;
};

class KeyboardEvent : public Event //just for the event handler
{
public:
    KeyboardEvent(SDL_Event e);
    virtual ~KeyboardEvent() = default;

    SDL_KeyboardEvent event;
};