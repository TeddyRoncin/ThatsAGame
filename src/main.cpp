#include <iostream>

#include "renderer/Renderer.h"

int main(int argc, char* argv[])
{
    Renderer renderer;
    renderer.Clear();
    renderer.AddTexture(0,0,"assets/img/test.png",10,10);
    renderer.Render();
    std::cin.get();
    return (0);
}
