#pragma once

// #include "entity/EntityType.h"

class Entity
{
public:
    Entity(float _x = 0.0f, float _y = 0.0f);
    virtual bool operator()(const Entity& e);
public:
    int GetID() const;
    // EntityType GetType() const;
    float GetX() const;
    float GetY() const;
    Position<float> GetPosition() const;
private:
    int m_ID;
protected:
    Position<float> m_Position;
    // const EntityType type;
};
