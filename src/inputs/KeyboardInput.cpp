#include "pch.h"

#include "inputs/KeyboardInput.h"

void KeyboardInput::Update(SDL_Event e)
{
    isPushDown = false;
    isPushUp = false;

    switch(e.type)
    {
    case SDL_KEYDOWN:
        try
        {
            m_isKeyDown.at(e.key.keysym.sym) = true;
        }
        catch(const std::out_of_range& exeption)
        {
            m_isKeyDown.insert( std::pair<int, bool>{e.key.keysym.sym, true});
        }

        isPushDown = true;
        key = e.key.keysym.sym;

        break;
    case SDL_KEYUP:
        try
        {
            m_isKeyDown.at(e.key.keysym.sym) = false;
        }
        catch(const std::out_of_range& exeption)
        {
            m_isKeyDown.insert( std::pair<int, bool>{e.key.keysym.sym, true});
        }
        break;

        isPushUp = true;
        key = e.key.keysym.sym;
    case SDL_TEXTEDITING:
    case SDL_TEXTINPUT:
        std::cerr << "editing text" << std::endl;
    default:
        std::cerr << "Keyboard event unandled : " << e.type << std::endl;
        break;
    };

    std::unique_ptr<Event> event{new KeyboardEvent{e}};
    EventHandler::addEvent(std::move(event));
}

bool KeyboardInput::isDown(int key)
{
    try
    {
        return m_isKeyDown.at(key);
    }
    catch(const std::out_of_range& e)
    {
        m_isKeyDown.at(key) = false; //assume that the key is up at the start of the program
        return false;
    }
    
}

bool KeyboardInput::isBeeingPushDown() const
{
    return isPushDown;
}

bool KeyboardInput::isBeeingPushUp() const
{
    return isPushUp;
}

int KeyboardInput::keyBeeingPush() const
{
    return key;
}

KeyboardEvent::KeyboardEvent(SDL_Event e)
{
    m_type = Et::KeyboardEvent;
    event = e.key;
}
