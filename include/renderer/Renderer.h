#pragma once

#include <unordered_map>

#include "renderer/Context.h"
#include "renderer/Texture/Texture.h"

class Renderer : protected Context
{
public:
	Renderer();
	~Renderer();

	void Clear();
	void Render();

	void AddTexture(int x, int y, const char* name, int width = 0, int height = 0);
	void RemoveTexture(const char* name);

private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	std::unordered_map<const char*, Texture> m_Textures;
};
