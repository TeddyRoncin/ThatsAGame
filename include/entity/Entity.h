#pragma once

#include "entity/EntityType.h"

class Entity
{
public:
	Entity(float _x = 0.0f, float _y = 0.0f);
	virtual ~Entity();
	virtual bool operator()(Entity& e);
public:
	int GetID() const;
	EntityType GetType() const;
	float GetX() const;
	float GetY() const;
	Position<float> GetPosition() const;
	virtual void Tick(float dt = 0.0f);
private:
	int m_ID;
protected:
	Position<float> m_Position;
	EntityType type;
};
