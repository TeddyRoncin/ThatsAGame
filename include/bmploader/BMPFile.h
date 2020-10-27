#pragma once

#include "bmploader/BMPImage.h"

class BMPFile
{
public:
    BMPFile(std::string fileName);
    ~BMPFile();
    BMPImage load();


private:
    void getFileContent();
    unsigned long getValue(size_t sizeToRead);
    void truncateFileContent(size_t sizeToTruncate);
    bool checkBMPSignature();
    void loadFileHeader();
    void loadImageHeader();
    bool loadImage();

private:
    std::string m_FileName;
    size_t m_FileSize;
    unsigned char* m_FileContent = nullptr;
    size_t m_CurrentByte;
    size_t m_Offset;
    size_t m_ImageHeaderSize;
    size_t m_ImageWidth;
    size_t m_ImageHeight;
    size_t m_BitDepth;
    size_t m_CompressionMethod;
    std::vector<int> m_Image;

};