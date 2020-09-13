#include "pch.h"

#include "game/Game.h"
#include "bmploader/BMPFile.h"

int main(int argc, char* argv[])
{
	/*BMPFile file("assets/maps/test.bmp");
	BMPImage img = file.load();
	std::cout << img.getWidth() << "   " << img.getHeight() << std::endl;
	for (size_t x = 0; x < img.getWidth(); x++) {
		for (size_t y = 0; y < img.getHeight(); y++) {
			RGBColor color = img.getRGBColor(x, y);
			std::cout << (int) color.R << " " << (int) color.G << " " << (int) color.B << "        ";
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;*/
	Game test;
	test.loop();
	std::vector<int> a;
	return EXIT_SUCCESS;
}
