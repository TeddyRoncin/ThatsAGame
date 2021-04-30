#pragma once

#include "ui/screen/Screen.h"

class ScreenManager
{
public:
    static void Init();
    static void Destroy();

public:
    static void Update();

    static void AddDemoScreen();

    static void RemoveScreen(int id);
    
private:
    static void AddScreen(Screen* screen);

private:
    static std::map<int, Screen*> m_Screens;
    static int m_CurrentId;
};