#include "pch.h"

#include "ui/Button.h"

Button::Button(const Position<float>& position, const Dimension<float>& size, int buttons, std::function<void (SDL_Event*)> callback)
    : UI(position, size), EventListener(this), m_Buttons(buttons), m_Callback(callback),
    m_CollisionBox(m_Position.getX(), m_Position.getY(), m_Size.getWidth(), m_Size.getHeight())
{
}

void Button::handle()
{
    if (m_CurrentEvent->type == SDL_MOUSEBUTTONDOWN && (m_Buttons & SDL_BUTTON(m_CurrentEvent->button.button)) == 1
        && m_CollisionBox.doesCollide(m_CurrentEvent->button.x, m_CurrentEvent->button.y))
    {
        m_Callback(m_CurrentEvent);
    }
}