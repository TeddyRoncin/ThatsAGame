#pragma once

#include <string>
#include <vector>
#include <fstream>

class MapLoader {

    public:
    static void registerMaps();

    private:
    MapLoader();
    MapLoader(std::string fileName);
    void loadMap();

    private:
    std::string& m_FileStream;

};
