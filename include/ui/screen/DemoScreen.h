#pragma once

#include "ui/screen/Screen.h"
#include "ui/Button.h"

class DemoScreen : public Screen
{
public:
    DemoScreen(int screenID);
    virtual void Draw();

private:
    void OnClick(SDL_Event* event);

private:
    int m_CurrentColor;
    int m_Direction;
    Button m_Button;  // We have to keep this listener so it is not detroyed
};