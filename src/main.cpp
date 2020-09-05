#include "pch.h"

#include "map/Map.h"
#include "map/MapManager.h"
#include "entity/player/Player.h"
#include "entity/npc/ai/PathFinder.h"

#include "renderer/Renderer.h"
#include "utils/Timer.h"
//#include "inputs/Inputs.h"

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
	
	MapManager::registerMaps();
	//OptionManager::load();
	Entity* player = new Player(0, 0);
    Map map = MapManager::getMap("Super Map ^^");
    //std::cout << map.getBackgroundPath() << std::endl;
    PathFinder pathfinder(map);
    std::vector<std::pair<int, int>> path = pathfinder.find(0, 2, 2, 2, player);
    for (std::pair<int, int> mapElement : path) {
        std::cout << mapElement.first << " " << mapElement.second << std::endl;
    }
	//Input i;
	unsigned int x(0);
	Renderer renderer;
	Timer timer(2);
	//OptionManager::load(renderer);
	while (true)//(!i.isQuitting())
	{
		x++;
		//render
		std::cerr << "je passe dans la boucle pour la " << x << "ieme(s) fois\n";
		renderer.RenderMap(map);
		renderer.AddTexture("assets/img/test.png", 100, 100);
		renderer.Render();
		//SDL_Delay(500);
		timer.waitForNextFrame();
		renderer.Clear();
		//inputs
		//SDL_Event events;
		//i.eventUpdate(events);
	}

    delete player;
    return EXIT_SUCCESS;
}
