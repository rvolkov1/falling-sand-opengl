#include <vector>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "src/ShaderClass.h"
#include "src/VAO.h"
#include "src/VBO.h"
#include "src/Sandbox.h"
#include "src/IO.h"

int main() 
{
  glfwInit();

  // tell GLFW which version of OpenGL we are using
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // hack to avoid odd behavior with retina displays
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

  const int width = 800;
  const int height = 800;

  // handle user input
  glfwSetCursorPosCallback(window, IO::mouseMoveCallback);
  glfwSetMouseButtonCallback(window, IO::mousePressCallback);

  // load GLAD so that it configues OpenGL
  gladLoadGL(); 

  Sandbox Sandbox(width, height);

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

  float lastTime = 0.0f;

  while (!glfwWindowShouldClose(window)) 
  {
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shaderProgram.Activate();

    Sandbox.Update();
    VBO1.Update(Sandbox.grid);

    VAO1.Bind();
    glDrawArrays(GL_TRIANGLES, 0, Sandbox.numPixelCols * Sandbox.numPixelRows * 6);
    VAO1.Unbind();
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);

    // handle GLFW events
    glfwPollEvents();

    // calc fps
    float currTime = glfwGetTime();
    float dt = currTime - lastTime;
    lastTime = currTime;
    //std::cout << "FPS: " << (1 / dt) << " / " << dt << std::endl;
  }

  VAO1.Delete();
  VBO1.Delete();
  shaderProgram.Delete();

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}