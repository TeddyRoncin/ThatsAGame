#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class Context
{
public:
	Context(Uint32 flags);
	~Context();
public:
	bool IsInitialised() const;
};