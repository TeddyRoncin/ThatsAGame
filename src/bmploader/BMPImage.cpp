#include "pch.h"

#include "bmploader/BMPImage.h"

BMPImage::BMPImage(size_t width, size_t height, size_t bitDepth, std::vector<int> image) :
    m_Width(width), m_Height(height), m_BitDepth(bitDepth), m_Image(image)
{

}

size_t BMPImage::getWidth()
{
    return m_Width;
}

size_t BMPImage::getHeight()
{
    return m_Height;
}

int BMPImage::getColor(size_t x, size_t y)
{
    return m_Image[x * m_Height + y];
}

RGBColor BMPImage::getRGBColor(size_t x, size_t y)
{
    size_t pixelIndex = y * m_Width + x;
    RGBColor color;
    color.R = m_Image[pixelIndex] & 0xFF;
    color.G = (m_Image[pixelIndex] >> 2) & 0xFF;
    color.B = (m_Image[pixelIndex] >> 2) & 0xFF;
    return color;
}