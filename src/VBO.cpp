#include "VBO.h"
#include <iostream>

VBO::VBO()
{
  glGenBuffers(1, &ID);
  // binding make certain object the current object, when we fire a command to modify an object, it will modify the object that is currently bound
  this->Bind();
  glBufferData(GL_ARRAY_BUFFER, 0, nullptr, GL_DYNAMIC_DRAW);
}

VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
  glGenBuffers(1, &ID);
  // binding make certain object the current object, when we fire a command to modify an object, it will modify the object that is currently bound
  glBindBuffer(GL_ARRAY_BUFFER, ID);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_DYNAMIC_DRAW);
}

void VBO::Bind()
{
  glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind()
{
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Update(std::vector<std::vector<int>> grid) {
  std::vector<float> vertices;
  float sizeX = 2.0f / grid[0].size();
  float sizeY = 2.0f / grid.size();

  //std::cout << sizeX << " " << sizeY << std::endl;

  float backgroundColor[] = {0, 0, 0};
  float sandColor[] = {0.70, 0.62, 0.41};
  float waterColor[] = {0.17, 0.46, 0.91};

  for (int y = 0; y < grid.size(); ++y) {
    for (int x = 0; x < grid[0].size(); ++x) {
      float posX = (float)x / grid[0].size() * 2.0f - 1.0f;
      float posY = (float)y / grid.size() * 2.0f - 1.0f;

      //std::cout << posX<< " " << posY << std::endl;

      float *currentColor;

      if (grid[y][x] == 0) {
        currentColor = backgroundColor;
      } else if (grid[y][x] == 1) {
        currentColor = sandColor;
      } else {
        currentColor = waterColor;
      }

      // x_pos, y_pos, rgb
      vertices.insert(vertices.end(), {
        posX, posY,
        currentColor[0], currentColor[1], currentColor[2],
        posX + sizeX, posY,
        currentColor[0], currentColor[1], currentColor[2],
        posX, posY + sizeY,
        currentColor[0], currentColor[1], currentColor[2],

        posX + sizeX, posY,
        currentColor[0], currentColor[1], currentColor[2],
        posX, posY + sizeY,
        currentColor[0], currentColor[1], currentColor[2],
        posX + sizeX, posY + sizeY,
        currentColor[0], currentColor[1], currentColor[2],
      });
    }
  }

  this->Bind();
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_DYNAMIC_DRAW);
  this->Unbind();
}

void VBO::Delete()
{
  glDeleteBuffers(1, &ID);
}

