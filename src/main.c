// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include "gl/ebo.h"
#include "gl/shader.h"
#include "gl/vao.h"
#include "gl/vbo.h"

#include "math/mat4.h"
#include "math/vec2.h"

#include "core/engine.h"
#include "core/input.h"

static Shader program;
static VBO vbo;
static EBO ebo;
static VAO vao;
static Vec2 pos;

void update(float dt) {
  Vec2 movement = VEC2_ZERO;
  if (input_key_down(KEY_W))
    movement.y -= 1.0f;
  if (input_key_down(KEY_S))
    movement.y += 1.0f;
  if (input_key_down(KEY_D))
    movement.x += 1.0f;
  if (input_key_down(KEY_A))
    movement.x -= 1.0f;

  movement = vec2_normalize(movement);

  float speed = 200.0f;
  pos.x += movement.x * speed * dt;
  pos.y += movement.y * speed * dt;

  if (input_key_pressed(KEY_ESCAPE))
    engine_quit();
}

void draw(void) {
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  Mat4 model = mat4_identity();
  model = mat4_translate(model, pos);
  model = mat4_scale(model, VEC2(100.0f, 100.0f));

  Mat4 view = mat4_view(VEC2(0.0f, 0.0f), 1.0f);
  Mat4 proj =
      mat4_ortho(0.0f, (float)window_width(), (float)window_height(), 0.0f);

  shader_bind(program);
  shader_uniform_mat4(program, "u_model", model);
  shader_uniform_mat4(program, "u_view", view);
  shader_uniform_mat4(program, "u_proj", proj);

  vao_bind(vao);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

int main(void) {
  WindowConfig config = {
      .width = 1080, .height = 720, .resizable = true, .title = "dust."};

  if (!engine_init(config))
    return 1;

  float vertices[] = {-0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f};
  uint32_t indexes[] = {0, 1, 2, 2, 3, 0};

  program =
      shader_from_files("assets/shaders/main.vert", "assets/shaders/main.frag");

  vbo = vbo_new(GL_STATIC_DRAW);
  ebo = ebo_new();
  vao = vao_new();

  vao_bind(vao);
  vbo_bind(vbo);
  vbo_data(vbo, vertices, sizeof(vertices));
  vao_attrib(vao, 0, 2, GL_FLOAT, sizeof(float) * 2, 0);
  ebo_bind(ebo);
  ebo_data(ebo, indexes, 6);
  vao_unbind();

  pos = VEC2(540.0f, 360.0f);

  engine_run(update, draw);

  vao_free(&vao);
  vbo_free(&vbo);
  ebo_free(&ebo);
  shader_free(&program);
  engine_shutdown();

  return 0;
}
