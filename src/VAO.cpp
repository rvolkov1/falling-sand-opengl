#include "VAO.h"

VAO::VAO(VBO VBO)
{
  glGenVertexArrays(1, &ID);
  this->Bind();
  this->LinkAttrib(VBO, 0, 2, GL_FLOAT, 5 * sizeof(float), (void*)(0));
  this->LinkAttrib(VBO, 1, 3, GL_FLOAT, 5 * sizeof(float), (void*)(2 * sizeof(float)));
  this->Unbind();
  VBO.Unbind();
}

void VAO::LinkAttrib(VBO VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
  VBO.Bind();
  // position of the vertex attribute, how many values per vertex, what kind of values, int or nah, amount of data between each vertex, (void)
  glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(layout);
  VBO.Unbind();
}

void VAO::Bind()
{
  glBindVertexArray(ID);
}

void VAO::Unbind()
{
  glBindVertexArray(0);
}

void VAO::Delete()
{
  glDeleteVertexArrays(1, &ID);
}