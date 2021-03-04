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
	static int CreateTexture(const Position<float>* position, const Dimension<float>* size, const char* texture, Layer layer);
	static int CreateTexture(Texture* texture, Layer layer);
	static void DeleteTexture(int id, Layer layer);

	static const std::array<std::map<int, Texture*>, Layer::LayerCount>& GetTextures();
private:
	static std::array<std::map<int, Texture*>, Layer::LayerCount> m_Textures;
	static std::map<const char*, std::pair<SDL_Texture*, int>> m_SDLTextures;
	static SDL_Renderer* m_Renderer;
};
