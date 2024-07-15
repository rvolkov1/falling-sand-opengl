#ifndef __IO_H
#define __IO_H

#include <GLFW/glfw3.h>
#include <set>
#include <iostream>

namespace IO {
  bool getMousePressState();
  std::pair<double, double> getMousePos();

  void keyPressCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
  void mouseMoveCallback(GLFWwindow* window, double xpos, double ypos);
  void mousePressCallback(GLFWwindow* window, int button, int action, int mods);
}

#endif