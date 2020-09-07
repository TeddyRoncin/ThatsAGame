#include "pch.h"

#include "inputs/Inputs.h"

#include "map/Map.h"
#include "map/MapManager.h"
#include "entity/player/Player.h"
#include "entity/npc/ai/PathFinder.h"

#include "renderer/Renderer.h"
#include "utils/Timer.h"

int main(int argc, char* argv[])
{
	MapManager::registerMaps();
	//OptionManager::load();
	Entity* player = new Player(0, 0);
    const Map map = MapManager::getMap("Super Map ^^");
    /*PathFinder pathfinder(map);
    std::vector<std::pair<int, int>> path = pathfinder.find(0, 2, 2, 2, player);
    for (std::pair<int, int> mapElement : path) {
        std::cout << mapElement.first << " " << mapElement.second << std::endl;
    }*/
	
	Input i;
	unsigned int x(0);
	Renderer renderer;
	renderer.RenderMap(map);
	//renderer.AddTexture("assets/img/test.png", 100, 100);
	//OptionManager::load(renderer);
	while (!i.isQuitting())
	{
		x++;
		//render
		std::cerr << "je passe dans la boucle pour la " << x << "ieme(s) fois\n";
		renderer.Render();
		SDL_Delay(500);
		renderer.Clear();
		//inputs
		SDL_Event events;
		i.eventUpdate(events);
	}

    delete player;
    return EXIT_SUCCESS;
}
