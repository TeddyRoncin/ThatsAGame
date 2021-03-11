#pragma once

#include "renderer/TextureManager.h"

class Renderable
{
public:
	Renderable();
	Renderable(const char* path, const Position<float>* position, const Dimension<float>* size, Layer layer, void* _texture_info = nullptr);
	virtual ~Renderable();
protected:
	int m_RendererID;
	Layer m_Layer;
};
