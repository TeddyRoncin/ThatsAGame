#include "pch.h"

#include "inputs/Inputs.h"

#include "map/Map.h"
#include "map/MapManager.h"
#include "entity/player/Player.h"
#include "entity/npc/ai/PathFinder.h"

#include "renderer/Renderer.h"
#include "utils/Timer.h"
#include "pngloader/Chunk.h"
#include "pngloader/PNGFile.h"
#include "pngloader/DeflateDecompressor.h"
/*
int DATA_LENGTH = 0;

unsigned char* load()
{
	std::ifstream file;
	unsigned char* content;
    if (file) {
        file.open("assets/maps/deflated.txt", std::ios::binary);
        file.seekg(0, std::ios::end);
        DATA_LENGTH = file.tellg();
        file.seekg(0, std::ios::beg);
        char* buffer = new char[DATA_LENGTH];
        file.read(buffer, DATA_LENGTH);
        unsigned char* content = new unsigned char[DATA_LENGTH];
        for (int i = 0; i < DATA_LENGTH; i++) {
            content[i] = (unsigned char) buffer[i];
        }
        delete[] buffer;
		unsigned char* buffer2 = content;
		delete[] content;
		return buffer2;
    }
}
*/
int main(int argc, char* argv[])
{
	//unsigned char* content = load();
	//DeflateDecompressor decompressor(content, DATA_LENGTH);
	//decompressor.decompress();
	//std::cout << (1 << 10) << std::endl;
	/*Chunk chunk;
	void* data = malloc(4 * sizeof(char));
	memset(data, 0x0000000D, 4);
	chunk.load(data);
	free(data);*/
	PNGFile file("assets/maps/map1.png");
	file.load();
	/*MapManager::registerMaps();
	//OptionManager::load();
	Entity* player = new Player(0, 0);
    Map& map = MapManager::getMap("Super Map ^^");
    PathFinder pathfinder(map);
    std::vector<std::pair<int, int>> path = pathfinder.find(0, 2, 2, 2, player);
    for (std::pair<int, int> mapElement : path) {
        std::cout << mapElement.first << " " << mapElement.second << std::endl;
    }
	Input i;
	unsigned int x(0);
	Renderer renderer;
	//Timer timer(2);
	//OptionManager::load(renderer);
	while (!i.isQuitting())
	{
		x++;
		//render
		std::cerr << "je passe dans la boucle pour la " << x << "ieme(s) fois\n";
		renderer.RenderMap(map);
		renderer.AddTexture("assets/img/test.png", 100, 100);
		renderer.Render();
		SDL_Delay(500);
		//timer.waitForNextFrame();
		renderer.Clear();
		//inputs
		SDL_Event events;
		i.eventUpdate(events);
	}

    delete player;*/
    return EXIT_SUCCESS;
}
