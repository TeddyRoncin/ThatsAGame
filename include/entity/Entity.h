#pragma once

#include <utility>

class Entity
{

public:
    Entity(float x, float y);
    std::pair<float, float> getPosition();
    float getX();
    float getY();
private:
    std::pair<float, float> m_Position;

};