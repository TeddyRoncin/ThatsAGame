#include "pch.h"
#include "application/Application.h"

#include "entity/ai/PathFinder.h"

int main(int argc, char* argv[])
{
	/*for (int t = 1; t < 100; t++)
	{
		auto start = std::chrono::system_clock::now();
		auto time = std::chrono::milliseconds(t);
		for (int i = 0; i < 10; i++)
		{
			std::this_thread::sleep_for(time);
		}
		int duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count();
		std::cout << t << ":" << duration / 10.0f - t << std::endl;
	}
	return EXIT_SUCCESS;*/
	Application app;
	app.loop();
	return EXIT_SUCCESS;
}
