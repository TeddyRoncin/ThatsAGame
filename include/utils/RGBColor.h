#pragma once

struct RGBColor
{
    Uint8 R, G, B;

    bool operator==(RGBColor color);
};

RGBColor getPixelColor(SDL_Surface* surface, size_t x, size_t y);