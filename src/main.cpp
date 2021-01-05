#include "pch.h"
#include "application/Application.h"

#include "test_folder/entity/ai/PathFinder.h"

int main(int argc, char* argv[])
{
	Map map;
	Entity e(0.0f, 2.0f);
	PathFinder p(map);
	auto path = p.find(&e, {2.f, 2.f}, 10);
	Application app;
	app.loop();
	return EXIT_SUCCESS;
}
