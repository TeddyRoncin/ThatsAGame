#pragma once

#include "renderer/Renderable.h"

typedef unsigned long long size_t;

struct SpriteSheetInfo
{
	int currentFrame;
	int xoffset, yoffset;
	int currentIndex;
	std::map<std::string, std::vector<int>> animationList;
	int frameNumber;

	void addAnimation(std::string name, std::vector<int> indicies);
};

class Animable : public Renderable
{
public:
	Animable(const char* path, const Position<float>* position, const Dimension<float>* size, Layer layer, SpriteSheetInfo info);
	virtual ~Animable();
public:
	void setAnimation(std::string name);
	void updateTexture(/*float dt*/);
private:
	SpriteSheetInfo m_Info;
	std::string m_AnimationState;
};

class TestAnimation : public Animable
{
public:
	TestAnimation(const char* path, const Position<float>* position, const Dimension<float>* size, Layer layer, SpriteSheetInfo info);
	virtual ~TestAnimation();
};
