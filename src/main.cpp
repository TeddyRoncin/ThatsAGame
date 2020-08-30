#include <iostream>
#include <SDL2/SDL.h>
#include <fstream>
#include <vector>
#include <string>

#include "map/MapLoader.h"
#include "map/MapManager.h"

int main(int argc, char* argv[])
{
	MapLoader::registerMaps();
	MapManager::getMap("test").getAt(0, 0)->display();
	return EXIT_SUCCESS;
}
