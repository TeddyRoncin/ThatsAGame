#pragma once

#include "renderer/Layer.h"

struct SpriteSheetInfo
{
	int currentFrame[2];
	int xoffset, yoffset;
	int currentIndex;
	std::map<std::string, int> animationIndex;
	std::map<int, std::vector<int>> animationList;

	SpriteSheetInfo addAnimation(std::string name, int y = -1, std::vector<int> indicies = { 0 });
};

class Animable
{
public:
	Animable(const char* path, const Position<float>* position, const Dimension<float>* size, Layer layer, const SpriteSheetInfo& info);
	virtual ~Animable();
public:
	void setAnimation(std::string name, int frame = -1);
	void updateTexture();
private:
	SpriteSheetInfo m_Info;
	int m_AnimationState;
	int m_RendererID;
	Layer m_Layer;
};
