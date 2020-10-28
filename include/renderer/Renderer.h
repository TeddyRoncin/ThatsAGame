#pragma once

#include "renderer/Layer.h"
#include "renderer/Context.h"
#include "renderer/texture/Texture.h"

#include "map/Maps.h"
#include "entity/Entity.h"

class Renderer : protected Context
{
public:
	Renderer();
	~Renderer();

	void Clear();
	void UpdateRender();
	void Present();

	void AddTexture(Texture&& texture, Layer layer = Layer::Middle);
	void AddTexture(const char* dir, size_t x = 0, size_t y = 0, size_t width = 0, size_t height = 0, Layer layer = Layer::Middle);

	void AddMap(const NewMap& map);
	void RenderEntity(const Entity& ent);

private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	std::array<std::list<Texture>, Layer::Layer_Length> m_Textures;
	size_t m_MapWidth;
	size_t m_MapHeight;
	size_t WINDOW_WIDTH = 600;
	size_t WINDOW_HEIGHT = 600;
};
