#include <iostream>
#include <SDL2/SDL.h>
#include <fstream>

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		std::cout << "An error happened during initialize SDL2 (SDL_INIT_VIDEO) : " << std::endl << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	SDL_Window *window = SDL_CreateWindow("Hello World !", 0, 0, 100, 100, SDL_WINDOW_RESIZABLE);
	if (window == nullptr) {
		std::cerr << "erreur window : " << SDL_GetError() << std::endl;
	}
	std::cin.get();
	SDL_Quit();
	return EXIT_SUCCESS;
}
