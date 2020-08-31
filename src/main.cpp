#include <iostream>
#include <math.h>

#include "renderer/Renderer.h"
#include "entity/npc/ai/PathFinder.h"
#include "map/MapLoader.h"
#include "map/Map.h"
#include "entity/player/Player.h"

int main(int argc, char* argv[])
{
    MapLoader::registerMaps();
    Entity* player = new Player(0, 0);
    Map map = MapManager::getMap("test");
    std::cout << map.getBackgroundPath() << std::endl;
    PathFinder pathfinder(map);
    std::vector<std::pair<int, int>> path = pathfinder.find(0, 2, 2, 2, player);
    for (std::pair<int, int> mapElement : path) {
        std::cout << mapElement.first << " " << mapElement.second << std::endl;
    }
    /*Renderer renderer;
    renderer.Clear();
    renderer.AddTexture(0,0,"assets/img/test.png", 10, 10);
    renderer.Render();
    std::cin.get();*/
    delete player;
    return (0);
}
