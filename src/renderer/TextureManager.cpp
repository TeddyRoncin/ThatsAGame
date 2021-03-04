#include "pch.h"

#include "renderer/TextureManager.h"

std::array<std::map<int, Texture*>, Layer::LayerCount> TextureManager::m_Textures = {};
std::map<const char*, std::pair<SDL_Texture*, int>> TextureManager::m_SDLTextures = {};
SDL_Renderer* TextureManager::m_Renderer = nullptr;

void TextureManager::Init(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
}

void TextureManager::Destroy()
{
	for (int layer = 0; layer < m_Textures.size(); layer++)
	{
		for (auto[id, texture] : m_Textures[layer])
		{
			DeleteTexture(id, (Layer) layer);
		}
		m_Textures[Layer::MapElements].clear();
	}
	// m_Textures[Layer::MapElements].clear();
	// m_Textures[Layer::InteractableElements].clear();
	// m_Textures[Layer::MovableElements].clear();
}

int TextureManager::CreateTexture(const Position<float>* position, const Dimension<float>* dimension, const char* texture_path, Layer layer)
{
	int current_id(RendererIDFactory());
	auto texture = m_SDLTextures.find(texture_path);
	if (texture == m_SDLTextures.end())
	{
		SDL_Texture* temp = IMG_LoadTexture(m_Renderer, texture_path);
		m_Textures[layer].emplace(current_id, new Texture(position, dimension, temp, texture_path));
		m_SDLTextures.emplace(texture_path, std::make_pair(temp, 1) );
		temp = nullptr;
	}
	else
	{
		m_Textures[layer].emplace(current_id, new Texture(position, dimension, m_SDLTextures[texture_path].first, texture_path));
		texture->second.second += 1;
	}
	return current_id;
}

int TextureManager::CreateTexture(Texture* texture, Layer layer)
{
	int currentId(RendererIDFactory());
	m_Textures[layer].emplace(currentId, texture);
	return currentId;
}

void TextureManager::DeleteTexture(int id, Layer layer)
{
	const char* path = m_Textures[layer].at(id)->texture_path;
	delete m_Textures[layer][id];
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

const std::array<std::map<int, Texture*>, Layer::LayerCount>& TextureManager::GetTextures()
{
	return m_Textures;
}
