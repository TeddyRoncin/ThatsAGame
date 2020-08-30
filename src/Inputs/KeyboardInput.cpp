#include "Inputs/KeyboardInput.h"

void KeyboardInput::Update(SDL_Event e)
{
    switch(e.type)
    {
    case SDL_KEYDOWN:
        m_isKeyDown.at(e.key.keysym.sym) = true;
        break;
    case SDL_KEYUP:
        m_isKeyDown.at(e.key.keysym.sym) = false;
        break;
    }
}

bool KeyboardInput::isDown(int key) const
{
    return m_isKeyDown.at(key);
}