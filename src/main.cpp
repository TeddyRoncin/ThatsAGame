#include "pch.h"
#include "application/Application.h"

#include "entity//ai/PathFinder.h"

int main(int argc, char* argv[])
{
	//Map map;
	//Entity e(0.0f, 20.0f);
	//PathFinder p(map);
	//auto path = p.find(&e, {20.f, 20.f}, 100);
	Application app;
	app.loop();
	return EXIT_SUCCESS;
}
