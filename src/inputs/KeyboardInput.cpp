#include "inputs/KeyboardInput.h"

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
        std::cerr << "Keyboard event unandled : " << e.type << std::endl;
        break;
    };

    std::unique_ptr<Event> event{new KeyboardEvent{e}};
    EventHandler::addEvent(std::move(event));
}

bool KeyboardInput::isDown(int key) const
{
    return m_isKeyDown.at(key);
}

KeyboardEvent::KeyboardEvent(SDL_Event e)
{
    m_type = Et::KeyboardEvent;
    event = e.key;
}
