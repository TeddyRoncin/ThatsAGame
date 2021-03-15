#include "pch.h"

#include "renderer/Animable.h"
#include "renderer/TextureManager.h"

SpriteSheetInfo SpriteSheetInfo::addAnimation(std::string name, std::vector<int> indicies)
{
	static int animationNumber(0);
	animationIndex.emplace(std::make_pair(name, animationNumber));
	animationList.emplace(std::make_pair(animationNumber, indicies));
	animationNumber++;
	return *this;
}

Animable::Animable(const char* path, const Position<float>* position, const Dimension<float>* size, Layer layer, const SpriteSheetInfo& info)
	:m_Info(info), m_RendererID(0), m_Layer(layer)
{
	m_RendererID = TextureManager::CreateTexture(position, size, path, m_Layer, &m_Info);
}

Animable::~Animable()
{
	TextureManager::DeleteTexture(m_RendererID, m_Layer);
}

void Animable::setAnimation(std::string name)
{
	if(m_AnimationState == m_Info.animationIndex[name]) {
		return;
	}
	m_AnimationState = m_Info.animationIndex[name];
	m_Info.currentIndex = 0;
	m_Info.currentFrame[0] = m_AnimationState;
	m_Info.currentFrame[1] = m_Info.animationList[m_AnimationState][m_Info.currentIndex];
}

void Animable::updateTexture()
{
	if(m_Info.currentIndex < m_Info.animationList[m_AnimationState].size() - 1) {
		m_Info.currentIndex++;
	} else {
		m_Info.currentIndex = 0;
	}
	m_Info.currentFrame[1] = m_Info.animationList[m_AnimationState][m_Info.currentIndex];
}
