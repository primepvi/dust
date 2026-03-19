// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <math.h>

#include "gl/shader.h"
#include "gl/vao.h"
#include "gl/vbo.h"
#include "gl/ebo.h"

#include "math/mat4.h"
#include "math/utils.h"
#include "math/vec2.h"

#include "core/window.h"

int main(void) {
  WindowConfig config = {
    .width = 800,
    .height = 600,
    .resizable = true,
    .title = "dust."
  };

  bool opened = window_open(config);
  if (!opened) return 1;
  
  Shader program =
      shader_from_files("assets/shaders/main.vert", "assets/shaders/main.frag");

  // clang-format off
  float vertices[] = {
    -0.5f, -0.5f,
    0.5f, -0.5f,
    0.5f, 0.5f,
    -0.5f, 0.5f
  };

  uint32_t indexes[] = {
    0, 1, 2,
    2, 3, 0
  };

  // clang-format on

  VBO vbo = vbo_new(GL_STATIC_DRAW);
  EBO ebo = ebo_new();

  VAO vao = vao_new();

  vao_bind(vao);
  vbo_bind(vbo);
  vbo_data(vbo, vertices, sizeof(vertices));
  vao_attrib(vao, 0, 2, GL_FLOAT, sizeof(float) * 2, 0);

  ebo_bind(ebo);
  ebo_data(ebo, indexes, 6);
  
  shader_bind(program);

  Mat4 model = mat4_identity();
  model = mat4_translate(model, VEC2(400.0f, 300.0f));
  model = mat4_scale(model, VEC2(300.0f, 300.0f));

  Mat4 view = mat4_view(VEC2(0.0f, 0.0f), 1.0f);
  Mat4 proj = mat4_ortho(0.0f, 800.0f, 600.0f, 0.0f);

  shader_uniform_mat4(program, "u_view", view);
  shader_uniform_mat4(program, "u_proj", proj);

  double prev = glfwGetTime();

  while (!window_should_close()) {
    double now = glfwGetTime();
    float dt = (float)(now - prev);
    prev = now;

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    model = mat4_rotate_z(model, DEG2RAD(45.0f) * dt);
    shader_uniform_mat4(program, "u_model", model);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    window_swap_buffers();
    window_poll_events();
  }

  shader_unbind();

  vao_unbind();
  vbo_unbind();
  ebo_unbind();

  vao_free(&vao);
  vbo_free(&vbo);
  ebo_free(&ebo);
  
  shader_free(&program);

  window_close();
  
  return 0;
}
