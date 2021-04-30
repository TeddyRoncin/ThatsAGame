#include "pch.h"

#include "ui/screen/ScreenManager.h"
#include "ui/screen/DemoScreen.h"

std::map<int, Screen*> ScreenManager::m_Screens = {};
int ScreenManager::m_CurrentId = 0;

void ScreenManager::Init()
{
}

void ScreenManager::Destroy()
{
    for (auto screenEntry : m_Screens)
    {
        delete screenEntry.second;
    }
}

void ScreenManager::Update()
{
    for (auto screenEntry : m_Screens)
    {
        screenEntry.second->Draw();
    }
}

void ScreenManager::AddDemoScreen()
{
    AddScreen(new DemoScreen(m_CurrentId));
}

void ScreenManager::AddScreen(Screen* screen)
{
    m_Screens.emplace(m_CurrentId++, screen);
}

void ScreenManager::RemoveScreen(int id)
{
    delete m_Screens.at(id);
    m_Screens.erase(id);
}