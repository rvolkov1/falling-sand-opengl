#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <vector>
#include <glad/glad.h>

class VBO
{
  public:
    GLuint ID;
    VBO();
    VBO(GLfloat* vertices, GLsizeiptr size);

    void Bind();
    void Unbind();
    void Update(std::vector<std::vector<int>> grid);
    void Delete();

};

#endif