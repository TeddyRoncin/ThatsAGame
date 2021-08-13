#pragma once

class UI
{
public:
    UI(const Position<float>& position, const Dimension<float>& size);
    virtual ~UI() = default;

protected:
    Position<float> m_Position;
    Dimension<float> m_Size;
};