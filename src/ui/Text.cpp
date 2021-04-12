#include "pch.h"
#include "ui/Text.h"

#include "renderer/TextureManager.h"

Text::Text(Position<float> position, Dimension<float> size, std::string text, TTF_Font* font)
    : UI(position, size), m_Text(text), m_Font(font), m_Layer(Layer::UI), m_RendererID(0), m_Texture(nullptr)
{
    SDL_Surface* texte = TTF_RenderText_Blended(m_Font, m_Text.c_str(), SDL_Color {0, 0, 20, 0});
    m_Size.dimension.first = texte->w;
    m_Size.dimension.second = texte->h;
    m_RendererID = TextureManager::CreateTexture(&m_Position, &m_Size, m_Layer);
    m_Texture = TextureManager::GetTexture(m_RendererID, m_Layer);
    SDL_UpdateTexture(m_Texture->texture, nullptr, texte->pixels, texte->pitch);
}

Text::Text(Position<float>& position, Dimension<float>& size, std::string& text, TTF_Font* font)
    : UI(position, size), m_Text(text), m_Font(font), m_Layer(Layer::UI), m_RendererID(0), m_Texture(nullptr)
{
    SDL_Surface* texte = TTF_RenderText_Blended(m_Font, m_Text.c_str(), SDL_Color {0, 0, 20, 0});
    m_Size.dimension.first = texte->w;
    m_Size.dimension.second = texte->h;
    m_RendererID = TextureManager::CreateTexture(&m_Position, &m_Size, m_Layer);
    m_Texture = TextureManager::GetTexture(m_RendererID, m_Layer);
    SDL_UpdateTexture(m_Texture->texture, nullptr, texte->pixels, texte->pitch);
}

Text::~Text()
{
    TTF_CloseFont(m_Font);
}

void Text::UpdateTexture()
{
    /* prepare surface formating */
    // SDL_PixelFormat* format = SDL_AllocFormat(SDL_PixelFormatEnum::SDL_PIXELFORMAT_RGBA32);
    // SDL_Surface* texte = TTF_RenderText_Blended(m_Font, m_Text.c_str(), SDL_Color {0, 0, 0, 255});
    // texte = SDL_ConvertSurface(texte, format, 0);
    // SDL_FreeFormat(format);
    // SDL_UpdateTexture(m_Texture->texture, nullptr, texte->pixels, texte->pitch);
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
    // UpdateTexture();
    m_Text = text;
}

void Text::SetFont(TTF_Font* font)
{
    // UpdateTexture();
    TTF_CloseFont(m_Font);
    m_Font = font;
}

