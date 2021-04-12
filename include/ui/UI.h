#pragma once

class UI
{
public:
    UI(const Position<float>& position, const Dimension<float>& size);

protected:
    Position<float> m_Position;
    Dimension<float> m_Size;
};