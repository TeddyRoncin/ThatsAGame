#include "pch.h"
#include "ui/Text.h"

#include "renderer/TextureManager.h"

Text::Text(const Position<float>& position, const Dimension<float>& size, const std::string& text, TTF_Font* font)
    : UI(position, size), m_Text(text), m_Font(font), m_RendererID(0)
{
    m_RendererID = TextureManager::CreateUIText(&m_Position, &m_Size, m_Font, m_Text.c_str());
}

Text::~Text()
{
    TTF_CloseFont(m_Font);
    TextureManager::DeleteUI(m_RendererID);
}

void Text::UpdateTexture()
{
    TextureManager::UpdateUIText(m_RendererID, m_Font, m_Text.c_str());
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

