#pragma once

#include "renderer/TextureManager.h"

class Renderable
{
public:
	Renderable(const char* path, const Position<float>* position, const Dimension<float>* size, Layer layer);
	Renderable(Texture* texture, Layer layer);
	virtual ~Renderable();
private:
	int m_RendererID;
	Layer m_Layer;
};
