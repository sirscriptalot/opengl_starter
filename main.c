#include "gfx.h"

int main(void) {
  gfx_t gfx;

  gfx_glfwWindow_create(&gfx, 800, 600, "Title");

  if (gfx_glfwWindow(&gfx) == NULL) {
    return 1;
  }

  while (!glfwWindowShouldClose(gfx_glfwWindow(&gfx))) {
    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glfwSwapBuffers(gfx_glfwWindow(&gfx));

    glfwPollEvents();
  }

  gfx_glfwWindow_delete(&gfx);

  return 0;
}
