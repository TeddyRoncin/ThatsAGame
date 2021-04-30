#include "pch.h"

#include "utils/RGBColor.h"

RGBColor::RGBColor()
	: R(0), G(0), B(0), A(0xFF)
{
}

RGBColor::RGBColor(int intColor)
	: A(intColor >> 24), R((intColor >> 16) & 0xFF), G((intColor >> 8) & 0xFF), B(intColor & 0xFF)
{
}

RGBColor::RGBColor(int r, int g, int b)
	: R(r), G(g), B(b), A(0xFF)
{
}

RGBColor::RGBColor(int r, int g, int b, int a)
	: R(r), G(g), B(b), A(a)
{
}

bool RGBColor::operator==(RGBColor color)
{
	return ( (R == color.R) && (G == color.G) && (B == color.B) && (A == color.A) );
}

int RGBColor::ToRGBInt()
{
	return (A << 24) | (R << 16) | (G << 8) | B;
}

std::ostream& operator<<(std::ostream& stream, RGBColor& color)
{
	stream << "RGBColor(R=" << (int) color.R << ",G=" << (int) color.G << ",B=" << (int) color.B << ",A=" << (int) color.A << ")";
	return stream;
}
