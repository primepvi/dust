#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "gl/shader.h"
#include "gl/vao.h"
#include "gl/vbo.h"

#include "math/vec2.h"

int main(void) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(800, 600, "dust", NULL, NULL);
  glfwMakeContextCurrent(window);

  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  Shader program =
      shader_from_files("assets/shaders/main.vert", "assets/shaders/main.frag");

  Vec2 vertices[] = {
      VEC2(-0.5f, -0.5f),
      VEC2(0.5f, -0.5f),
      VEC2(0.f, 0.5f),
  };

  VBO vbo = vbo_new(GL_STATIC_DRAW);
  VAO vao = vao_new();

  vao_bind(vao);
  vbo_bind(vbo);

  vbo_data(vbo, vertices, sizeof(vertices));
  vao_attrib(vao, 0, 2, GL_FLOAT, sizeof(float) * 2, 0);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shader_bind(program);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    shader_unbind();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  vao_unbind();
  vbo_unbind();

  vao_free(&vao);
  vbo_free(&vbo);
  shader_free(&program);

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
