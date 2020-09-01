#pragma once

class Entity
{

public:
    Entity(float x, float y);
    std::pair<float, float> getPosition() const;
    float getX() const;
    float getY() const;
private:
    std::pair<float, float> m_Position;

};