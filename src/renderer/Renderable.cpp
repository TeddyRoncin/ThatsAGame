#include "pch.h"

#include "renderer/Renderable.h"

Renderable::Renderable(const char* path, const Position<float>* position, const Dimension<float>* size, Layer layer, void* _texture_info)
	:m_RendererID(0), m_Layer(layer)
{
	m_RendererID = TextureManager::CreateTexture(position, size, path, layer, _texture_info);
}

Renderable::~Renderable()
{
	TextureManager::DeleteTexture(m_RendererID, m_Layer);
}
