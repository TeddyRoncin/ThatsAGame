#pragma once


#include "MouseInput.h"
#include "KeyboardInput.h"
#include "WindowsInput.h"

#include "SDL2/SDL.h"

class Input
{
public:
    Input();

    void eventUpdate(SDL_Event events); //where events are updated

    bool isQuitting();

    KeyboardInput m_keys; //in public so we can check them easely
    MouseInput m_mouse;
    WindowsInput m_window;

private:
    bool m_quit;
};

