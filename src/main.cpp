#include <iostream>
#include <math.h>

#include "renderer/Renderer.h"
//#include "entity/npc/ai/PathFinder.h"
#include "map/MapLoader.h"
#include "map/Map.h"
//#include "entity/player/Player.h"
//#include "map/MapLoader.h"
//#include "map/MapManager.h"

int main(int argc, char* argv[])
{
    MapLoader::registerMaps();
    /*
    Entity* player = new Player(0, 0);
    Map map = MapManager::getMap("test");
    std::cout << map.getBackgroundPath() << std::endl;
    PathFinder pathfinder(map);
    std::vector<std::pair<int, int>> path = pathfinder.find(0, 2, 2, 2, player);
    for (std::pair<int, int> mapElement : path) {
        std::cout << mapElement.first << " " << mapElement.second << std::endl;
    }
    delete player;
    */
    Renderer renderer;
    renderer.Clear();
    renderer.RenderMap(MapManager::getMap("test"));
    renderer.AddTexture("assets/img/test.png");
    renderer.Render();
    std::cin.get();
    return (0);
}
