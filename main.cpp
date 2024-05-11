#include <math.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "src/ShaderClass.h"
#include "src/VAO.h"
#include "src/VBO.h"
#include "src/EBO.h"

/*
// vertices for triangle
GLfloat vertices[] = 
{
  -0.5f, -0.5f * float(sqrt(3)) / 3,     0.0f,   // lower left corner
  0.5f,  -0.5f * float(sqrt(3)) / 3,     0.0f,     // lower right corner
  0.0f,   0.5f * float(sqrt(3)) * 2 / 3, 0.0f,  // upper corner
  -0.25f, 0.5f * float(sqrt(3)) / 6,     0.0f, // Inner left
  0.25f,  0.5f * float(sqrt(3)) / 6,     0.0f,  // inner right
  0.0f,  -0.5f * float(sqrt(3)) / 3,     0.0f,     // inner down 
};
*/

GLfloat vertices[] = 
{
  //       COORDINATES                        /  COLORS 
  -0.5f, -0.5f, 0.0f,     1.0f,   0.0f,  0.0f, 0.0f, 0.0f, // lower left corner
  -0.5f,  0.5f, 0.0f,     0.0f,   1.0f,  0.0f, 0.0f, 1.0f, // lower right corner
  0.5f,   0.5f, 0.0f,     0.0f,   0.0f,  1.0f, 1.0f, 1.0f, // upper corner
  0.5f,  -0.5f, 0.0f,     1.0f,   1.0f,  1.0f, 1.0f, 0.0f, // Inner left
};

GLuint indices[] = 
{
  0, 2, 1, // lower triangle
  0, 3, 2, // lower right triangle
};


int main() 
{
  glfwInit();

  // tell GLFW which version of OpenGL we are using
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // hack for mac
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // create GLFW window
  GLFWwindow* window = glfwCreateWindow(800, 800, "Tutorial Window", NULL, NULL);

  if (window == NULL) 
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  // use window
  glfwMakeContextCurrent(window);

  // load GLAD so that it configues OpenGL
  gladLoadGL();
  
  int width = 800;
  int height = 800;

  glfwSetWindowPos(window, width / 2, height / 2);
  glfwGetWindowSize(window, &width, &height);

  printf("%d, %d\n", width, height);

  // not sure
  glViewport(0, 0, width, height);
  Shader shaderProgram("default.vert", "default.frag");

  VAO VAO1;
  VAO1.Bind();
  
  VBO VBO1(vertices, sizeof(vertices));
  EBO EBO1(indices, sizeof(indices));

  VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
  VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
  VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  VAO1.Unbind();
  VBO1.Unbind();
  EBO1.Unbind();

  GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

  //Texture
  int widthImg, heightImg, numColCh;
  stbi_set_flip_vertically_on_load(true);
  unsigned char* bytes = stbi_load("icon.png", &widthImg, &heightImg, &numColCh, 0);

  GLuint texture;
  glGenTextures(1, &texture);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  // float flat_color[] = {1.0f, 1.0f, 0.5f, 1.0f};
  // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flat_color);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(bytes);
  glBindTexture(GL_TEXTURE_2D, 0);

  GLuint tex0Uni = glGetUniformLocation(shaderProgram.ID, "tex0");
  shaderProgram.Activate();
  glUniform1i(tex0Uni, 0);

  // set color buffer
  glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
  // clean the back buffer ans assign a new color to it
  glClear(GL_COLOR_BUFFER_BIT);
  // swap back and front buffers
  glfwSwapBuffers(window);

  while (!glfwWindowShouldClose(window)) 
  {
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shaderProgram.Activate();

    glUniform1f(uniID, 0.5f);
    glBindTexture(GL_TEXTURE_2D, texture);

    VAO1.Bind();

    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);

    // handle GLFW events
    glfwPollEvents();
  }

  VAO1.Delete();
  VBO1.Delete();
  EBO1.Delete();
  glDeleteTextures(1, &texture);
  shaderProgram.Delete();

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}