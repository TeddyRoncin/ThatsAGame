#include "pch.h"

#include "test_folder/renderer/TextureManager.h"

std::map<const char*, std::pair<SDL_Texture*, int>> TextureManager::m_Textures = {};
SDL_Renderer* TextureManager::m_Renderer = nullptr;

void TextureManager::Init(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
}

void TextureManager::Destroy()
{
    for (auto texture : m_Textures)
    {
        if (texture.second.first)
        {
            SDL_DestroyTexture(texture.second.first);
        }
    }
}

void TextureManager::LoadTexture(const char* path)
{
    auto texture = m_Textures.find(path);
    if (texture == m_Textures.end())
    {
        m_Textures.insert({ path, {IMG_LoadTexture(m_Renderer, path), 1} });
    }
    else
    {
        texture->second.second += 1;
    }
}

SDL_Texture* TextureManager::GetTexture(const char* path)
{
    auto texture = m_Textures.find(path);
    if (texture == m_Textures.end())
    {
        std::cerr << "Texture not found : " << path << std::endl;
        LoadTexture(path);
        return m_Textures.at(path).first;
    }
    else
    {
        texture->second.second += 1;
        return texture->second.first;
    }
}

void TextureManager::UnloadTexture(const char* path)
{
    auto texture = m_Textures.find(path);
    if (texture != m_Textures.end())
    {
        texture->second.second -= 1;
        if (texture->second.second == 0)
        {
            if (texture->second.first) {
                SDL_DestroyTexture(texture->second.first);
            }
            m_Textures.erase(path);
        }
    }
}