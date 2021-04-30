#pragma once

#include "ui/UI.h"
#include "event/EventListener.h"
#include "utils/CollisionBox.h"

class Button : public UI, EventListener
{
public:
    Button(const Position<float>& position, const Dimension<float>& size, int buttons, std::function<void (SDL_Event* event)> callback);
    virtual void handle();

private:
    int m_Buttons;
    CollisionBox m_CollisionBox;
    std::function<void (SDL_Event*)> m_Callback;
};