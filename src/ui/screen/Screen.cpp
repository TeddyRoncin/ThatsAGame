#include "pch.h"

#include "ui/screen/Screen.h"
#include "renderer/TextureManager.h"

Screen::Screen(int screenID, const Position<int>& position, const Dimension<int>& size)
    : UI({0, 0}, Dimension<float>(size.getWidth(), size.getHeight())), m_Loaded(false), m_Canvas(nullptr), m_ScreenID(screenID)
{
}

Screen::~Screen()
{
    SDL_FreeSurface(m_Canvas);
}

void Screen::Load()
{
    m_RendererID = TextureManager::CreateUIScreen(&m_Position, &m_Size);
    m_Loaded = true;
}

void Screen::Unload()
{
    if (m_Loaded)
    {
        TextureManager::DeleteUI(m_RendererID);
        m_Loaded = false;
    }
}

void Screen::ResetCanvas()
{
    SDL_FreeSurface(m_Canvas);
    m_Canvas = SDL_CreateRGBSurfaceWithFormat(0, m_Size.getWidth(), m_Size.getHeight(), 32, SDL_PixelFormatEnum::SDL_PIXELFORMAT_ARGB8888);
}

void Screen::FinalizeDraw()
{
    TextureManager::UpdateUIScreen(m_RendererID, m_Canvas);
}

void Screen::AddButton(const Button& button)
{
    m_Buttons.emplace_back(button);
}
