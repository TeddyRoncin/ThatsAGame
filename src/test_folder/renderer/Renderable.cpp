#include "pch.h"

#include "test_folder/renderer/Renderable.h"

Renderable::Renderable(char* path, Position<float> position, Dimension<float> size)
	:m_Texture(path, position, size)
{}

Texture Renderable::GetTexture() const
{
	return m_Texture;
}
