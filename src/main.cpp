#include <iostream>
#include <math.h>

#include "map/Map.h"
#include "map/MapLoader.h"
#include "map/MapManager.h"
#include "entity/player/Player.h"
#include "entity/npc/ai/PathFinder.h"

#include "renderer/Renderer.h"
#include "inputs/Inputs.h"

int main(int argc, char* argv[])
{
    /*
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		std::cout << "An error happened during initialize SDL2 (SDL_INIT_VIDEO) : " << std::endl << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	SDL_Window *window = SDL_CreateWindow("Hello World !", 0, 0, 100, 100, SDL_WINDOW_RESIZABLE);
	if (window == nullptr) {
		std::cerr << "erreur window : " << SDL_GetError() << std::endl;
	}
	*/
	Input i;

	bool continuer = true;
	
	MapLoader::registerMaps();
	Entity* player = new Player(0, 0);
    Map map = MapManager::getMap("test");
    std::cout << map.getBackgroundPath() << std::endl;
    PathFinder pathfinder(map);
    std::vector<std::pair<int, int>> path = pathfinder.find(0, 2, 2, 2, player);
    for (std::pair<int, int> mapElement : path) {
        std::cout << mapElement.first << " " << mapElement.second << std::endl;
    }


	renderer.RenderMap(MapManager::getMap("test"));
	renderer.AddTexture(0,0,"assets/img/test.png", 10, 10);
	while(continuer)
	{
		//render
		renderer.Clear();
    	Renderer renderer;
		//inputs
		SDL_Event events;
		i.eventUpdate(events);
		continuer = !i.isQuitting();
	}

    delete player;

    return EXIT_SUCCESS;
}
