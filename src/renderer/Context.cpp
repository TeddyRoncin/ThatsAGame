#include "pch.h"

#include "renderer/Context.h"

Context::Context(Uint32 flags)
{
	if (SDL_Init(flags) != 0) {
		std::cerr << "SDL_InitError : " << SDL_GetError() << std::endl;
	}
	if (TTF_Init() == -1) {
		std::cerr << "TTF_InitError : " << TTF_GetError() << std::endl;
	}
	if (IMG_Init(IMG_InitFlags::IMG_INIT_JPG | IMG_InitFlags::IMG_INIT_PNG) == -1) {
		std::cerr << "IMG_InitError : " << IMG_GetError() << std::endl;
	}
	if(Mix_Init(MIX_InitFlags::MIX_INIT_FLAC | MIX_InitFlags::MIX_INIT_MP3) == -1) {
		std::cerr << "MXR_InitError : " << Mix_GetError() << std::endl;
	}
}

Context::~Context()
{
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

bool Context::IsInitialised() const
{
	return (true);
}