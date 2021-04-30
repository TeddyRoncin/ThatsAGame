#include "pch.h"

#include "renderer/Renderable.h"
#include "renderer/TextureManager.h"

Renderable::Renderable(const char* path, const Position<float>* position, const Dimension<float>* size, Layer layer)
	:m_RendererID(0), m_Layer(layer)
{
	m_RendererID = TextureManager::CreateTexture(position, size, path, layer);
}

Renderable::~Renderable()
{
	TextureManager::DeleteTexture(m_RendererID, m_Layer);
}
