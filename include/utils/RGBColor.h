#pragma once

struct RGBColor
{
	Uint8 R, G, B, A;

	RGBColor();
	RGBColor(int intColor);
	RGBColor(int r, int g, int b);
	RGBColor(int r, int g, int b, int a);

	bool operator==(RGBColor color);
	int ToRGBInt();
};

std::ostream& operator<<(std::ostream& stream, RGBColor& color);