#pragma once

class UI
{
public:
    UI(Position<float>& position, Dimension<float>& size);

protected:
    Position<float> m_Position;
    Dimension<float> m_Size;
};