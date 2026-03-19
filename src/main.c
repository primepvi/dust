// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <math.h>

#include "gl/shader.h"
#include "gl/vao.h"
#include "gl/vbo.h"

#include "math/color.h"
#include "math/mat4.h"
#include "math/utils.h"
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

  shader_bind(program);

  Mat4 model = mat4_identity();
  model = mat4_translate(model, VEC2(400.0f, 300.0f));
  model = mat4_scale(model, VEC2(300.0f, 300.0f));

  Mat4 view = mat4_view(VEC2(0.0f, 0.0f), 1.0f);
  Mat4 proj = mat4_ortho(0.0f, 800.0f, 600.0f, 0.0f);

  shader_uniform_mat4(program, "u_view", view);
  shader_uniform_mat4(program, "u_proj", proj);

  double prev = glfwGetTime();

  while (!glfwWindowShouldClose(window)) {
    double now = glfwGetTime();
    float dt = (float)(now - prev);
    prev = now;

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    model = mat4_rotate_z(model, DEG2RAD(45.0f) * dt);
    shader_uniform_mat4(program, "u_model", model);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  shader_unbind();

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
