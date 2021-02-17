#pragma once

#include "event/EventListener.h"
#include "entity/MovableEntity.h"

class Player : public EventListener, public MovableEntity
{
public:
	Player(Position<float> position);
	virtual void handle();
	virtual bool operator()(Entity& entity) override;
private:
	Position<float> m_LastPos;
};
