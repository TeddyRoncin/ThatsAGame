#pragma once

#include <cstdio>
#include <string>

#include "MouseInput.h"
#include "KeyboardInput.h"

#include "SDL2/SDL.h"

class Input
{
public:
    Input();

    void eventUpdate(SDL_Event events); //where events are updated

    bool isQuitting();
private:
    KeyboardInput m_keys;
    MouseInput m_mouse;

    bool m_quit;
};
