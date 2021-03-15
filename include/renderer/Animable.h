#pragma once

#include "renderer/Layer.h"

struct SpriteSheetInfo
{
	int currentFrame[2];
	int xoffset, yoffset;
	int currentIndex;
	std::map<std::string, int> animationIndex;
	std::map<int, std::vector<int>> animationList;

	SpriteSheetInfo addAnimation(std::string name, std::vector<int> indicies);
};

class Animable
{
public:
	Animable(const char* path, const Position<float>* position, const Dimension<float>* size, Layer layer, const SpriteSheetInfo& info);
	virtual ~Animable();
public:
	void setAnimation(std::string name);
	void updateTexture();
private:
	SpriteSheetInfo m_Info;
	int m_AnimationState;
	int m_RendererID;
	Layer m_Layer;
};
