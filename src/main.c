#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "gl/shader.h"
#include "gl/vao.h"
#include "gl/vbo.h"

#include "math/vec2.h"
#include "math/color.h"

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

  Color colors[] = {COLOR_GREEN, COLOR_BLUE, COLOR_RED};

  VBO vertices_vbo = vbo_new(GL_STATIC_DRAW);
  VBO colors_vbo = vbo_new(GL_STATIC_DRAW);
  
  VAO vao = vao_new();

  vao_bind(vao);
  vbo_bind(vertices_vbo);
  vbo_data(vertices_vbo, vertices, sizeof(vertices));
  vao_attrib(vao, 0, 2, GL_FLOAT, sizeof(float) * 2, 0);

  vbo_bind(colors_vbo);
  vbo_data(colors_vbo, colors, sizeof(colors));
  vao_attrib(vao, 1, 4, GL_FLOAT, sizeof(float) * 4, 0);
  
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
  vbo_free(&vertices_vbo);
  vbo_free(&colors_vbo);
  shader_free(&program);

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
