#include "IO.h"

namespace IO {
  static int height = 800;
  static int width = 800;

  static std::pair<double, double> mousePos;
  static std::set<char> keys_pressed;
  static bool mousePress;

  bool getMousePressState()
  {
    return mousePress;
  }

  std::pair<double, double> getMousePos() {
    if (mousePos.first < 0 || mousePos.first >= width || mousePos.second < 0 || mousePos.second >= height) {
      return {-1, -1};
    }

    return {mousePos.first, mousePos.second};
  }

  void keyPressCallback(GLFWwindow* window, int key, int scancode, int action, int mods) 
  {
    std::cout << "keypress: " << key << std::endl;
  }

  void mouseMoveCallback(GLFWwindow* window, double xpos, double ypos)
  {
    //std::cout << "mouse move: " << xpos << " " << ypos << std::endl;
    mousePos.first = xpos;
    mousePos.second = ypos;
  }

  void mousePressCallback(GLFWwindow* window, int button, int action, int mods)
  {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) 
    {
      mousePress = true;
    }

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) 
    {
      mousePress = false;
    }
  }
}
