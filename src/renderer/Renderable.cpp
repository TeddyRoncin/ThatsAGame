#include "pch.h"

#include "renderer/Renderable.h"

Renderable::Renderable(const char* path, const Position<float>* position, const Dimension<float>* size)
	:m_RendererID(0)
{
	m_RendererID = TextureManager::CreateTexture(position, size, path);
}

Renderable::~Renderable()
{
	TextureManager::DeleteTexture(m_RendererID);
}