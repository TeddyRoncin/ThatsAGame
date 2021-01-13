#pragma once

#include "renderer/Texture.h"

class Renderable
{
public:
	Renderable(const char* path, Position<float> position, Dimension<float> size);
	virtual Texture& GetTexture();

protected:
	Texture m_Texture;

};
