#pragma once

#include "test_folder/renderer/Texture.h"

class Renderable
{
public:
	Renderable(char* path, Position<float> position, Dimension<float> size);

	Texture GetTexture() const
	{
		return m_Texture;
	}

private:
	Texture m_Texture;
};
