#pragma once

#include "test_folder/renderer/Texture.h"

class Renderable
{
public:
	Renderable(const char* path, Position<float> position, Dimension<float> size);

	virtual Texture GetTexture();

protected:
	virtual void UpdateTexture(Texture texture) = 0;

private:
	Texture m_Texture;
};
