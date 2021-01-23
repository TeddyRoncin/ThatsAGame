#pragma once

struct CollisionBox
{
public:
    const int m_X;
    const int m_Y;
    const int m_Width;
    const int m_Height;

public:
    CollisionBox(int x, int y, int width, int height);
public:
    bool doesCollide(CollisionBox& other);
};