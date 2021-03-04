#include "pch.h"
#include "ui/Text.h"

Text::Text(Position<int> position, Dimension<int> size, std::string text, TTF_Font* font)
    : UI(position, size), Renderable(this, Layer::InteractableElements), Texture((Position<float>*) &m_Position, (Dimension<float>*) &m_Size),
      m_Text(text), m_Font(font), m_Update(true)
{
}

Text::~Text()
{
    TTF_CloseFont(m_Font);
    SDL_DestroyTexture(texture);
}

void Text::Draw(SDL_Renderer* renderer)
{
    if (m_Update)
    {
        UpdateTexture(renderer);
    }
    SDL_Rect pos {m_Position.getX(), m_Position.getY(), m_Size.getWidth(), m_Size.getHeight()};
    SDL_RenderCopy(renderer, texture, NULL, &pos);
}

void Text::UpdateTexture(SDL_Renderer* renderer)
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
    }
    SDL_Surface* surf = TTF_RenderText_Solid(m_Font, m_Text.c_str(), SDL_Color {0, 0, 0, 0});
    texture = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
}

const Position<int>& Text::GetPosition() const
{
    return m_Position;
}

const Dimension<int>& Text::GetSize() const
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

void Text::SetPosition(const Position<int>& pos)
{
    m_Position = pos;
}

void Text::SetSize(const Dimension<int>& size)
{
    m_Size = size;
}

void Text::SetText(const std::string& text)
{
    m_Text = text;
    m_Update = true;
}

void Text::SetFont(TTF_Font* font)
{
    TTF_CloseFont(m_Font);
    m_Font = font;
    m_Update = true;
}

