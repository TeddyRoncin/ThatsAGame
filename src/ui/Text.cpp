#include "pch.h"
#include "ui/Text.h"

Text::Text(Position<float> position, Dimension<float> size, std::string text, TTF_Font* font)
    : UI(position, size), Renderable(&m_Position, &m_Size, Layer::UI),
      m_Text(text), m_Font(font)
{
    m_Texture = TextureManager::GetTexture(m_RendererID, m_Layer);
    UpdateTexture();
}

Text::Text(Position<float>& position, Dimension<float>& size, std::string& text, TTF_Font* font)
    : UI(position, size), Renderable(&m_Position, &m_Size, Layer::UI),
      m_Text(text), m_Font(font)
{
    m_Texture = TextureManager::GetTexture(m_RendererID, m_Layer);
    UpdateTexture();
}

Text::~Text()
{
    TTF_CloseFont(m_Font);
}

void Text::UpdateTexture()
{
    /*if (m_Texture->texture != nullptr)
    {
        SDL_DestroyTexture(m_Texture->texture);
    }*/
    SDL_Surface* surf = TTF_RenderText_Solid(m_Font, m_Text.c_str(), SDL_Color {0, 255, 0, 255});
    void* pixels;
    int pitch;
    SDL_LockTexture(m_Texture->texture, nullptr, &pixels, &pitch);
    SDL_ConvertPixels(surf->w, surf->h,
               surf->format->format,
               surf->pixels, surf->pitch,
               SDL_PIXELFORMAT_RGB888,
               pixels, pitch);
    SDL_UnlockTexture(m_Texture->texture);
    //SDL_UpdateTexture(m_Texture->texture, nullptr, surf->pixels, surf->pitch);
    SDL_FreeSurface(surf);
}

const Position<float>& Text::GetPosition() const
{
    return m_Position;
}

const Dimension<float>& Text::GetSize() const
{
    return m_Size;
}

const std::string& Text::GetText() const
{
    return m_Text;
}

const TTF_Font* Text::GetFont() const
{
    return m_Font;
}

void Text::SetPosition(const Position<float>& pos)
{
    m_Position = pos;
}

void Text::SetSize(const Dimension<float>& size)
{
    m_Size = size;
}

void Text::SetText(const std::string& text)
{
    UpdateTexture();
    m_Text = text;
}

void Text::SetFont(TTF_Font* font)
{
    UpdateTexture();
    TTF_CloseFont(m_Font);
    m_Font = font;
}

