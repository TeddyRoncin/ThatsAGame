#pragma once

#include <unordered_map>

#include "renderer/Context.h"
#include "renderer/Texture/Texture.h"

#include "map/Map.h"

class Renderer : protected Context
{
public:
	Renderer();
	~Renderer();

	void Clear();
	void Render();

	void AddTexture(size_t x, size_t y, const char* name, size_t width = 0, size_t height = 0);
	void RemoveTexture(const char* name);

	void RenderMap(const Map& map);

private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	std::unordered_map<const char*, Texture> m_Textures;
};
