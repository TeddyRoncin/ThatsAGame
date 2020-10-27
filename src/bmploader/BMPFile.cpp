#include "pch.h"

#include "bmploader/BMPFile.h"

BMPFile::BMPFile(std::string fileName) :
    m_FileName(fileName)
{

}

BMPFile::~BMPFile()
{
    delete[] m_FileContent;
}

BMPImage BMPFile::load()
{
    m_CurrentByte = 0;
    getFileContent();
    if (!checkBMPSignature()) {
        // std::cerr << m_FileName << " is not a BMP file" << std::endl;
        return BMPImage(0, 0, 0, std::vector<int>());
    }
    loadFileHeader();
    loadImageHeader();
    // std::cout   << "m_Offset : " << m_Offset << std::endl
    //             << "m_ImageHeaderSize : " << m_ImageHeaderSize << std::endl
    //             << "m_ImageWidth : " << m_ImageWidth << std::endl
    //             << "m_ImageHeight : " << m_ImageHeight << std::endl
    //             << "m_BitDepth : " << m_BitDepth << std::endl
    //             << "m_CompressionMethod : " << m_CompressionMethod << std::endl;
    if (!loadImage()) {
        return BMPImage(0, 0, 0, std::vector<int>());
    }
    return BMPImage(m_ImageWidth, m_ImageHeight, m_BitDepth, m_Image);
}

void BMPFile::getFileContent()
{
    std::ifstream file;
    if (file) {
        file.open(m_FileName, std::ios::binary);
        file.seekg(0, std::ios::end);
        m_FileSize = file.tellg();
        file.seekg(0, std::ios::beg);
        char* buffer = new char[m_FileSize];
        file.read(buffer, m_FileSize);
        delete[] m_FileContent;
        m_FileContent = new unsigned char[m_FileSize];
        for (int i = 0; i < m_FileSize; i++) {
            m_FileContent[i] = (unsigned char) buffer[i];
        }
        delete[] buffer;
    }
}

unsigned long BMPFile::getValue(size_t sizeToRead)
{
    unsigned long result = 0;
    for (int i = 0; i < sizeToRead; i++) {
        result += std::pow(256, i) * m_FileContent[i + m_CurrentByte];
    }
    m_CurrentByte += sizeToRead;
    return result;
}

bool BMPFile::checkBMPSignature()
{
    return getValue(2) == 0x4D42;
}

void BMPFile::loadFileHeader()
{
    m_CurrentByte += 4;
    m_CurrentByte += 4;
    m_Offset = getValue(4);
}

void BMPFile::loadImageHeader()
{
    m_CurrentByte += 4;
    m_ImageWidth = getValue(4);
    m_ImageHeight = getValue(4);
    m_CurrentByte += 2;
    m_BitDepth = getValue(2);
    m_CompressionMethod = getValue(4);
    m_CurrentByte += 20;
}

bool BMPFile::loadImage()
{
    if (m_BitDepth != 24) {
        // std::cerr << "Only 24 bit depth is allowed at the moment in the BMP parser" << std::endl;
        return false;
    }
    if (m_CompressionMethod != 0) {
        // std::cerr << "Only compression method 0 is allowed at the moment in the BMP parser" << std::endl;
        return false;
    }
    m_Image = std::vector<int>();
    for (int i = 0; i < m_ImageWidth * m_ImageHeight; i++) {
        m_Image.push_back(0);
    }
    for (int y = m_ImageHeight - 1; y >= 0; y--) {
        for (int x = 0; x < m_ImageWidth; x++) {
            //std::cout << x << y << std::endl;
            m_Image[x * m_ImageHeight + y] = getValue(3);
            //std::cout << m_Image[x * m_ImageHeight + y] << std::endl;
        }
        m_CurrentByte += 4 - (m_ImageHeight * 3) % 4;
    }
    return true;
}