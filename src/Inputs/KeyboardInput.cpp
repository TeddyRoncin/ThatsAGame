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
    default:
        fprintf(stderr, "Keyboard event unandled : " + events.type);
        break;
    }

    KeyboardEvent ke(e);
}

bool KeyboardInput::isDown(int key) const
{
    return m_isKeyDown.at(key);
}

virtual KeyboardEvent::KeyboardEvent(SDL_Event e)
{
    m_type = KeyboardEvent;
    event = e.key;
}
