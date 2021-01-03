#pragma once

#include "test_folder/renderer/Texture.h"

class Renderable
{
public:
	Renderable(const char* path, Position<float> position, Dimension<float> size);

	virtual Texture GetTexture() const;

private:
	Texture m_Texture;
};
