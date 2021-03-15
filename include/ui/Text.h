// #pragma once

// #include "ui/UI.h"
// #include "renderer/Renderable.h"
// #include "renderer/Texture.h"

// class Text : public UI, Renderable
// {
// public:
//     Text(Position<int> position, Dimension<int> dimension, std::string text, TTF_Font* font);
//     Text(Position<int>& position, Dimension<int>& dimension, std::string& text, TTF_Font* font);
//     ~Text();

// public:
//     virtual void Draw(SDL_Renderer* renderer);
//     const Position<int>& GetPosition() const;
//     const Dimension<int>& GetSize() const;
//     const std::string& GetText() const;
//     const TTF_Font* GetFont() const;
//     void SetPosition(const Position<int>& position);
//     void SetSize(const Dimension<int>& size);
//     void SetText(const std::string& text);
//     void SetFont(TTF_Font* font);

// protected:
//     void UpdateTexture(SDL_Renderer* renderer);
//     std::string m_Text;
//     TTF_Font* m_Font;
//     bool m_Update;
// };