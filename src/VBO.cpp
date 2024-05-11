#include "VBO.h"

VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
  glGenBuffers(1, &ID);
  // binding make certain object the current object, when we fire a command to modify an object, it will modify the object that is currently bound
  glBindBuffer(GL_ARRAY_BUFFER, ID);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VBO::Bind()
{
  glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind()
{
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
  glDeleteBuffers(1, &ID);
}

