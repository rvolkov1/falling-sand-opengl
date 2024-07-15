#include "Sandbox.h"

Sandbox::Sandbox(int width, int height) {
  this->numPixelRows = height / this->tileSize;
  this->numPixelCols = width / this->tileSize;

  for (int row = 0; row < this->numPixelRows; ++row) {
    std::vector<int> curr;
    for (int col = 0; col < this->numPixelCols; ++col) {
      //int val = std::rand() % 2;
      curr.push_back(0);
    }
    grid.push_back(curr);
  }

  grid[10][10] = 1;
}



void Sandbox::Update() {
  if (IO::getMousePressState()) 
  {
    std::pair<double, double> mousePos = IO::getMousePos();

    if (mousePos.first >= 0 && mousePos.second >= 0) 
    {
      int tileX = mousePos.first / this->tileSize;
      int tileY = this->numPixelRows - int(mousePos.second / this->tileSize);

      for (int i = 0; i < 10; ++i) {
        int dx = rand() % 5;
        int dy = rand() % 5;

        if (tileX + dx < this->numPixelRows && tileY + dy < this->numPixelRows) {
          this->grid[tileY + dy][tileX + dx] = 1;
        }
      }
    }
  }

  for (int row = 1; row < grid.size(); ++row) {
    for (int col = 0; col < grid[0].size(); ++col) {
      if (grid[row][col] == 1) 
      {
        if (grid[row-1][col] == 0) 
        {
        grid[row-1][col] = 1;
        grid[row][col] = 0;
        } 
        else if (col > 0 && grid[row-1][col-1] == 0) 
        {
        grid[row-1][col-1] = 1;
        grid[row][col] = 0;
        } 
        else if (col < this->numPixelCols-1 && grid[row-1][col+1] == 0) 
        {
        grid[row-1][col+1] = 1;
        grid[row][col] = 0;
        }
      } 
    }
  }
}