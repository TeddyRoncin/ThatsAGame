#pragma once

#include "pch.h"

class UI
{
public:
    UI(Position<int>& position, Dimension<int>& size);

protected:
    Position<int> m_Position;
    Dimension<int> m_Size;
};