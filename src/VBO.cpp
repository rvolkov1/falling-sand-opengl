#include "VBO.h"

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

void VBO::Update() {
  std::vector<float> vertices;
  float sizeX = 2.0f / 10;
  float sizeY = 2.0f / 10;

  for (int y = 0; y < 10; ++y) {
    for (int x = 0; x < 10; ++x) {
      float posX = (float)x / 10 * 2.0f - 1.0f;
      float posY = (float)y / 10 * 2.0f - 1.0f;

      // x_pos, y_pos, rgb
      vertices.insert(vertices.end(), {
        posX, posY,
        0.70, 0.62, 0.41,
        posX + sizeX, posY,
        0.70, 0.62, 0.41,
        posX, posY + sizeY,
        0.70, 0.62, 0.41,

        posX + sizeX, posY,
        0.17, 0.46, 0.91,
        posX, posY + sizeY,
        0.17, 0.46, 0.91,
        posX + sizeX, posY + sizeY,
        0.17, 0.46, 0.91
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

