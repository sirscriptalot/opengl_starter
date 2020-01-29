#include <assert.h>

#include "gfx.h"

GLFWwindow * gfx_glfwWindow(const gfx_t * gfx) {
  return gfx->glfwWindow;
}

void gfx_glfwWindow_create(gfx_t * gfx, int width, int height, char * title) {
  if (glfwInit() != GLFW_TRUE) {
    return;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GFX_GL_MAJOR_VERSION);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GFX_GL_MINOR_VERSION);

  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GFX_GL_FORWARD_COMPAT);

  gfx->glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);

  if (gfx->glfwWindow == NULL) {
    glfwTerminate();

    return;
  }

  glfwMakeContextCurrent(gfx->glfwWindow);

  glewExperimental = GL_TRUE;

  if (glewInit() != GLEW_OK) {
    gfx_glfwWindow_delete(gfx);

    return;
  }
}

void gfx_glfwWindow_delete(gfx_t * gfx) {
  if (gfx->glfwWindow == NULL) {
    gfx_glfwWindow_delete_null(gfx);

    return;
  }

  glfwDestroyWindow(gfx->glfwWindow);

  gfx->glfwWindow = NULL;

  glfwTerminate();
}

void gfx_glfwWindow_delete_null(const gfx_t * gfx) {
  assert(gfx->glfwWindow == NULL); // catch logic errors

  glfwTerminate();
}
