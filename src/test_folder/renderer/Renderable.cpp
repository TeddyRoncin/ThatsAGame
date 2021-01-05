#include "pch.h"

#include "test_folder/renderer/Renderable.h"

Renderable::Renderable(const char* path, Position<float> position, Dimension<float> size)
	:m_Texture(path, position, size)
{}

Texture& Renderable::GetTexture()
{
	return m_Texture;
}
