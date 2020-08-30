#pragma once

#include <map>
#include "SDL2/SDL.h"

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
    virtual KeyboardEvent(SDL_Event e);
    SDL_KeyboardEvent event;
};