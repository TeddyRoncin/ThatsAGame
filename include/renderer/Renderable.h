#pragma once

#include "renderer/TextureManager.h"

class Renderable
{
public:
	Renderable(const Position<float>* position, const Dimension<float>* size, Layer layer);
	Renderable(const char* path, const Position<float>* position, const Dimension<float>* size, Layer layer);
	virtual ~Renderable();
protected:
	int m_RendererID;
	Layer m_Layer;
};
