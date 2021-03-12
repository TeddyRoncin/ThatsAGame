#pragma once

#include "ui/UI.h"
#include "event/EventListener.h"
#include "utils/CollisionBox.h"

class Button : public UI, EventListener
{
public:
    Button(Position<int>& position, Dimension<int>& size, int buttons);
    virtual void handle();

private:
    int m_Buttons;
    CollisionBox m_CollisionBox;
};