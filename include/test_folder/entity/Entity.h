#pragma once

// #include "test_folder/entity/EntityType.h"

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
private:
    int m_ID;
    Position<float> m_Position;
protected:
    // const EntityType type;
};
