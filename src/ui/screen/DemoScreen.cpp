#include "pch.h"

#include "ui/screen/DemoScreen.h"
#include "utils/RGBColor.h"
#include "ui/screen/ScreenManager.h"

DemoScreen::DemoScreen(int screenID)
    : Screen(screenID, {0, 0}, {100, 100}), m_CurrentColor(0), m_Direction(1),
    m_Button(Button({0, 0}, {100, 100}, SDL_BUTTON_LMASK, [this](SDL_Event* event) -> void {OnClick(event);}))
{
    Load();
}

void DemoScreen::Draw()
{
    ResetCanvas();
    SDL_FillRect(m_Canvas, NULL, RGBColor(m_CurrentColor, m_CurrentColor, m_CurrentColor).ToRGBInt());
    m_CurrentColor += m_Direction;
    if (m_CurrentColor <= 0 || m_CurrentColor >= 255)
    {
        m_Direction = -m_Direction;
    }
    FinalizeDraw();
}

void DemoScreen::OnClick(SDL_Event* event)
{
    Unload();
    ScreenManager::RemoveScreen(m_ScreenID);
}