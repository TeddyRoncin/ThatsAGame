#pragma once

#include <map>
#include "SDL2/SDL.h"

class KeyboardInput
{
public:
    KeyboardInput() = default;

    void Update(SDL_Event e);

    bool isDown(int key) const;
private:
    std::map<int, bool> m_isKeyDown;
};