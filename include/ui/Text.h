#pragma once

#include "ui/UI.h"
#include "renderer/Renderable.h"
#include "renderer/Texture.h"

class Text : public UI, Renderable
{

public:
    Text(Position<float> position, Dimension<float> dimension, std::string text, TTF_Font* font);
    Text(Position<float>& position, Dimension<float>& dimension, std::string& text, TTF_Font* font);
    ~Text();

public:
    const Position<float>& GetPosition() const;
    const Dimension<float>& GetSize() const;
    const std::string& GetText() const;
    const TTF_Font* GetFont() const;
    void SetPosition(const Position<float>& position);
    void SetSize(const Dimension<float>& size);
    void SetText(const std::string& text);
    void SetFont(TTF_Font* font);

protected:
    void UpdateTexture();
    std::string m_Text;
    TTF_Font* m_Font;

private:
    Texture* m_Texture;

};
