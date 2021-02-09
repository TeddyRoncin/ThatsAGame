#include "pch.h"

#include "entity/Player.h"

Player::Player(Position<float> position)
    :EventListener(this), MovableElement("assets/textures/player.png", position, {0.5f, 0.5f}), m_LastPos(0.0f, 0.0f)
{
}

void Player::handle()
{
    m_LastPos = m_Position;
    switch (m_Action)
    {
        case Action::PlayerUp: m_Position.position.second -= 0.1f; return;
        case Action::PlayerDown: m_Position.position.second += 0.1f; return;
        case Action::PlayerLeft: m_Position.position.first -= 0.1f; return;
        case Action::PlayerRight: m_Position.position.first += 0.1f; return;
    }
}

bool Player::operator()(Entity& e)
{
    if(e.GetType() == EntityType::MapElement && !e(*this)) {
        m_Position = m_LastPos;
    }
    return false;
}
