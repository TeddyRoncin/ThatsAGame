#pragma once

#include "renderer/TextureManager.h"

class Renderable
{
public:
	Renderable(const char* path, const Position<float>* position, const Dimension<float>* size);
	~Renderable();
private:
	int m_RendererID;
};
