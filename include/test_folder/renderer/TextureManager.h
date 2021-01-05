#pragma once

class TextureManager
{
public:
    static void Init(SDL_Renderer* renderer);
    static void Destroy();
    static void LoadTexture(const char* path);
    static SDL_Texture* GetTexture(const char* path);
    static void UnloadTexture(const char* path);

private:
    static std::map<const char*, std::pair<SDL_Texture*, int>> m_Textures;
    static SDL_Renderer* m_Renderer;
};