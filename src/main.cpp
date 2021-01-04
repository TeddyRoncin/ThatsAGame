#include "pch.h"
#include "application/Application.h"

#include "test_folder/entity/ai/PathFinder.h"
#include "map/Map.h"
#include "test_folder/entity/Entity.h"

int main(int argc, char* argv[])
{
	//Application app;
	//app.loop();
	Map map;
	PathFinder pathfinder = PathFinder(map);
	Entity entity(1, 1);
	std::vector<Position<float>> path = pathfinder.find(&entity, Position<float>(2.0f, 2.0f), 3);
	for (int i = 0; i < path.size(); i++) {
		std::cout << path[i].getX() << "   " << path[i].getY() << std::endl;
	}
	return EXIT_SUCCESS;
}
