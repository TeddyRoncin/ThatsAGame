#include "pch.h"
#include "application/Application.h"

//#include "test_folder/entity/ai/PathFinder.h"
//#include "map/Map.h"

int main(int argc, char* argv[])
{
	Application app;
	app.loop();
	/*Map map();
	PathFinder pathfinder = PathFinder(map);
	pathfinder.find({0, 0}, {1, 1}, nullptr, 100);*/
	return EXIT_SUCCESS;
}
