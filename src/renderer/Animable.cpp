#include "pch.h"
#include "renderer/Animable.h"

void SpriteSheetInfo::addAnimation(std::string name, std::vector<int> indicies)
{
	animationList.emplace(std::make_pair(name, indicies));
}

Animable::Animable(const char* path, const Position<float>* position, const Dimension<float>* size, Layer layer, SpriteSheetInfo info)
	:Renderable(path, position, size, layer, &m_Info), m_Info(info)
{
}

Animable::~Animable()
{
}

void Animable::setAnimation(std::string name)
{
	m_AnimationState = name;
	m_Info.currentIndex = 0;
	m_Info.currentFrame = m_Info.animationList[m_AnimationState][m_Info.currentIndex];
}

void Animable::updateTexture(/*float dt*/)
{
	m_Info.currentIndex++;
	m_Info.currentFrame = m_Info.animationList[m_AnimationState][m_Info.currentIndex];
}
