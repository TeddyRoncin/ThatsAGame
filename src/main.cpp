#include <iostream>

#include "renderer/Renderer.h"
#include "map/MapLoader.h"
#include "map/MapManager.h"

int main(int argc, char* argv[])
{
    MapLoader::registerMaps();
    Renderer renderer;
    renderer.Clear();
    renderer.RenderMap(MapManager::getMap("test"));
    renderer.AddTexture(0,0,"assets/img/test.png",100,100);
    renderer.Render();
    std::cin.get();
    return (0);
}
