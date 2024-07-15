#ifndef SANDBOX_CLASS_H
#define SANDBOX_CLASS_H

#include <vector>

class Sandbox
{
  public:
    std::vector<std::vector<int>> grid;
    int tileSize = 10;
    int numPixelRows;
    int numPixelCols;

    Sandbox(int width, int height);
    void Update();
};

#endif