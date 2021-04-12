#pragma once

#include "renderer/Texture.h"

static int RendererIDFactory()
{
	static int id(-1);
	id++;
	return id;
}

class TextureManager
{
public:
	static void Init(SDL_Renderer* renderer);
	static void Destroy();
	static int CreateTexture(const Position<float>* position, const Dimension<float>* size, const char* texture, Layer layer, void* _texture_info = nullptr);
	static void DeleteTexture(int id, Layer layer);

	static int CreateUIText(const Position<float>* position, const Dimension<float>* size, TTF_Font* font, const char* text);
	static void UpdateUIText(int id, TTF_Font* font, const char* text);
	static void DeleteUI(int id);

	static Texture* GetTexture(int id, Layer layer);
	static Texture* GetUITexture(int id);
	static const std::array<std::map<int, Texture>, Layer::LayerCount>& GetTextures();
	static const std::map<int, Texture>& GetUITextures();

private:
	static std::array<std::map<int, Texture>, Layer::LayerCount> m_Textures;
	static std::map<const char*, std::pair<SDL_Texture*, int>> m_SDLTextures;
	static std::map<int, Texture> m_UITextures;
	static SDL_Renderer* m_Renderer;
};
