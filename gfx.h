#ifndef GFX_H
#define GFX_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GFX_GL_MAJOR_VERSION 3

#define GFX_GL_MINOR_VERSION 3

#define GFX_GL_PROFILE GLFW_OPENGL_CORE_PROFILE

#define GFX_GL_FORWARD_COMPAT GL_TRUE

typedef struct gfx {
  GLFWwindow * glfwWindow;
} gfx_t;

GLFWwindow * gfx_glfwWindow(const gfx_t * gfx);

void gfx_glfwWindow_create(gfx_t * gfx, int width, int height, char * title);

void gfx_glfwWindow_delete(gfx_t * gfx);

void gfx_glfwWindow_delete_null(const gfx_t * gfx);

#endif
