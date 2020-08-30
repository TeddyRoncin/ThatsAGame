#pragma once

#include <utility>

class Entity
{

public:
    std::pair<float, float> getPosition();
    float getX();
    float getY();
private:
    std::pair<float, float> m_Position;

};