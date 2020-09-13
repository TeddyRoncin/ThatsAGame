#pragma once

#include "utils/Utils.h"

class BMPImage
{

public:
    BMPImage(size_t width, size_t height, size_t bitDepth, std::vector<int> image);
    size_t getWidth();
    size_t getHeight();
    int getColor(size_t x, size_t y);
    RGBColor getRGBColor(size_t x, size_t y);

private:
    size_t m_Width;
    size_t m_Height;
    size_t m_BitDepth;
    std::vector<int> m_Image;

};