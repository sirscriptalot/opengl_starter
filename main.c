#include <GL/glew.h>
#include <GLFW/glfw3.h>

void terminate(GLFWwindow * window) {
  if (window) {
    glfwDestroyWindow(window);
  }

  glfwTerminate();
}

int main(void) {
  if (glfwInit() != GLFW_TRUE) {
    return 1;
  }

  // Require OpenGL >= 3.3, the oldest version of OpenGL that implements
  // the modern API.
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  // Configure OpenGL to use the core profile, the profile implemented
  // by the hardware vendor.
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Do not depend deprecated behavior to make upgrading OpenGL
  // versions easier when needed.
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow * window = glfwCreateWindow(800, 600, "Starter", NULL, NULL);

  if (window == NULL) {
    terminate(NULL);

    return 1;
  }

  glfwMakeContextCurrent(window);

  // Global flag to tell glew to load the modern OpenGL interface.
  glewExperimental = GL_TRUE;

  if (glewInit() != GLEW_OK) {
    terminate(window);

    return 1;
  }

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  terminate(window);

  return 0;
}
