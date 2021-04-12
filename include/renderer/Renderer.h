#pragma once

#include "application/ApplicationState.h"
#include "renderer/TextureManager.h"

class Renderer
{

public:
	Renderer(const ApplicationState* const state, SDL_Window* window);
	~Renderer();
	void SetWindowSize(Dimension<int> newSize);
	void Render();

private:
	void RenderHome();
	void RenderGame();

	void RenderTextures();
	void DrawTexture(const Texture& texture, int x, int y, int width, int height);

private:
	const ApplicationState* const m_State;
	SDL_Renderer* m_Renderer;
	Dimension<int> m_WindowSize;

};
