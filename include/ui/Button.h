#pragma once

#include "ui/UI.h"
#include "event/EventListener.h"
#include "utils/CollisionBox.h"

class Button : public UI, EventListener
{
public:
    Button(Position<float>& position, Dimension<float>& size, int buttons);
    virtual void handle();

private:
    int m_Buttons;
    CollisionBox m_CollisionBox;
};