#pragma once

#include "utils/RGBColor.h"
#include "ui/UI.h"
#include "ui/Button.h"

class Screen : public UI
{
public:
    Screen(int screenID, const Position<int>& position, const Dimension<int>& size);
    ~Screen();
    virtual void Draw() = 0;
    virtual void Load();
    virtual void Unload();

protected:
    void ResetCanvas();
    void FinalizeDraw();
    void AddButton(const Button& button);

protected:
    SDL_Surface* m_Canvas;
    RGBColor m_BackgroundColor;
    bool m_Loaded;
    const int m_ScreenID;

private:
    int m_RendererID;
    std::vector<Button> m_Buttons;
};