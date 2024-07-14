#include <vector>
#include <math.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "src/ShaderClass.h"
#include "src/VAO.h"
#include "src/VBO.h"

// vertices for triangle
GLfloat vertices[] = 
{
  -0.5f, -0.5f * float(sqrt(3)) / 3,     0.0f,   // lower left corner
  0.5f,  -0.5f * float(sqrt(3)) / 3,     0.0f,     // lower right corner
  0.0f,   0.5f * float(sqrt(3)) * 2 / 3, 0.0f,  // upper corner
};
/*
GLfloat vertices[] = 
{
  //       COORDINATES                        /  COLORS 
  -0.5f, -0.5f, 0.0f,     1.0f,   0.0f,  0.0f, // lower left corner
  -0.5f,  0.5f, 0.0f,     0.0f,   1.0f,  0.0f, // lower right corner
  0.5f,   0.5f, 0.0f,     0.0f,   0.0f,  1.0f, // upper corner
  0.5f,  -0.5f, 0.0f,     1.0f,   1.0f,  1.0f, // Inner left
};
*/

GLuint indices[] = 
{
  0, 2, 1, // lower triangle
  0, 3, 2, // lower right triangle
};

int grid[10][10] = {0};

int main() 
{
  glfwInit();

  // tell GLFW which version of OpenGL we are using
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_FALSE);

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
  
  const int width = 800;
  const int height = 800;

  printf("%d, %d\n", width, height);

  // not sure
  glViewport(0, 0, width, height);
  Shader shaderProgram("default.vert", "default.frag");

  VBO VBO1;
  VAO VAO1(VBO1);

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

    VBO1.Update();

    VAO1.Bind();
    glDrawArrays(GL_TRIANGLES, 0, 10 * 10 * 6);
    VAO1.Unbind();
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);

    // handle GLFW events
    glfwPollEvents();
  }

  VAO1.Delete();
  VBO1.Delete();
  shaderProgram.Delete();

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}