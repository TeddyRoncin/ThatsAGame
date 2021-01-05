#include "pch.h"

#include "test_folder/entity/RenderableEntity.h"

RenderableEntity::RenderableEntity(const char* path, Position<float> position, Dimension<float> size, Layer priority)
	:Entity(position.getX(), position.getY()), Renderable(path, position, size), m_RenderPriorityLevel(priority)
{
}

Layer RenderableEntity::GetRenderPriorityLevel() const
{
	return m_RenderPriorityLevel;
}

Texture& RenderableEntity::GetTexture()
{
	m_Texture.position = GetPosition();
	m_Texture.size = {1, 1};
	/*if (m_Texture.needReloading){
		std::cout << "bonjour !" << std::endl;
	}*/
	//m_Texture.needReloading = true;
	return m_Texture;
}
