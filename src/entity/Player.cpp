#include "pch.h"

#include "entity/Player.h"
#include "event/EventBinding.h"

Player::Player(Position<float> position)
    : MovableEntity("assets/textures/player.png", position, {0.5f, 0.5f}), EventListener(this)
{

}

void Player::handle()
{
    switch (m_Action)
    {
        case Action::PlayerUp: m_Position.position.second -= 0.01f; return;
        case Action::PlayerDown: m_Position.position.second += 0.01f; return;
        case Action::PlayerLeft: m_Position.position.first -= 0.01f; return;
        case Action::PlayerRight: m_Position.position.first += 0.01f; return;
    }
}