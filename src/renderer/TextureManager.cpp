#include "pch.h"

#include "renderer/TextureManager.h"
#include "map/Map.h"

std::array<std::map<int, Texture>, Layer::LayerCount> TextureManager::m_Textures = {};
std::map<const char*, std::pair<SDL_Texture*, int>> TextureManager::m_SDLTextures = {};
std::map<int, Texture> TextureManager::m_UITextures = {};
SDL_Renderer* TextureManager::m_Renderer = nullptr;

void TextureManager::Init(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
}

void TextureManager::Destroy()
{
	m_Textures[Layer::MapElements].clear();
	m_Textures[Layer::InteractableElements].clear();
	m_Textures[Layer::MovableElements].clear();
	for (auto[path, texture] : m_SDLTextures)
	{
		SDL_DestroyTexture(texture.first);
	}
	m_SDLTextures.clear();
	for (auto[id, texture] : m_UITextures)
	{
		SDL_DestroyTexture(texture.texture);
	}
	m_UITextures.clear();
	m_Renderer = nullptr;
}

int TextureManager::CreateTexture(const Position<float>* position, const Dimension<float>* dimension, const char* texture_path, Layer layer, void* _texture_info)
{
	int current_id(RendererIDFactory());
	auto texture = m_SDLTextures.find(texture_path);
	if (texture == m_SDLTextures.end())
	{
		SDL_Texture* temp = IMG_LoadTexture(m_Renderer, texture_path);
		if(!temp) {
			std::cerr << "error loading texture : " << IMG_GetError() << std::endl;
		}
		m_Textures[layer].emplace(current_id, Texture(position, dimension, temp, texture_path, _texture_info));
		m_SDLTextures.emplace(texture_path, std::make_pair(temp, 1) );
		temp = nullptr;
	}
	else
	{
		m_Textures[layer].emplace(current_id, Texture(position, dimension, texture->second.first, texture_path, _texture_info));
		texture->second.second += 1;
	}
	return current_id;
}

void TextureManager::DeleteTexture(int id, Layer layer)
{
	const char* path = m_Textures[layer].at(id).texture_path;
	m_Textures[layer].erase(id);
	auto texture = m_SDLTextures.find(path);
	if (texture != m_SDLTextures.end())
	{
		texture->second.second -= 1;
		if (texture->second.second == 0)
		{
			if (texture->second.first) {
				SDL_DestroyTexture(texture->second.first);
			}
			m_SDLTextures.erase(path);
		}
	}
}


int TextureManager::CreateUIText(const Position<float>* position, const Dimension<float>* size, TTF_Font* font, const char* text)
{
	int current_id(RendererIDFactory());
	SDL_Surface* surf = TTF_RenderText_Blended(font, text, SDL_Color {0, 0, 20, 0});
	m_UITextures.emplace(current_id, Texture(position, size, nullptr));
	SDL_FreeSurface(surf);
	return current_id;
}

void TextureManager::UpdateUIText(int id, TTF_Font* font, const char* text)
{
	int current_id(RendererIDFactory());
	SDL_Surface* surf = TTF_RenderText_Blended(font, text, SDL_Color {0, 0, 20, 0});
	Texture& texture = m_UITextures.at(id);
	SDL_DestroyTexture(texture.texture);
	texture.texture = SDL_CreateTextureFromSurface(m_Renderer, surf);
	SDL_FreeSurface(surf);
}

int TextureManager::CreateUIScreen(const Position<float>* position, const Dimension<float>* size)
{
	int current_id(RendererIDFactory());
	m_UITextures.emplace(current_id, Texture(position, size, SDL_CreateTextureFromSurface(m_Renderer, nullptr)));
	return current_id;
}

void TextureManager::UpdateUIScreen(int id, SDL_Surface* surface)
{
	Texture& texture = m_UITextures.at(id);
	SDL_DestroyTexture(texture.texture);
	texture.texture = SDL_CreateTextureFromSurface(m_Renderer, surface);
	std::cout << surface << std::endl;
}

void TextureManager::DeleteUI(int id)
{
	SDL_DestroyTexture(m_UITextures.at(id).texture);
	m_UITextures.erase(id);
}

Texture* TextureManager::GetTexture(int id, Layer layer)
{
	return &m_Textures[layer].at(id);
}

Texture* TextureManager::GetUITexture(int id)
{
	return &m_UITextures.at(id);
}

const std::array<std::map<int, Texture>, Layer::LayerCount>& TextureManager::GetTextures()
{
	return m_Textures;
}

const std::map<int, Texture>& TextureManager::GetUITextures()
{
	return m_UITextures;
}
