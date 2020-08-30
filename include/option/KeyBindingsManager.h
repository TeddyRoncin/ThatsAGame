#pragma once

#include "pch.h"

enum KeyBindings
{
    GoForward,
    GoBackwards,
    GoLeftwards,
    GoRightwards,
    OpenInventory,
    OpenParameters
}

class KeyBindingsManager
{
public:
    KeyBindingsManager();

    void Init();

private:
    std::map<int, KeyBindings> options;
}