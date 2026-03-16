#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

  const char *vert_src = "#version 330 core\n"
                         "layout(location=0) in vec3 a_pos;\n"
                         "void main() {\n"
                         "    gl_Position = vec4(a_pos, 1.0);\n"
                         "}\n";

  const char *frag_src = "#version 330 core\n"
                         "out vec4 frag_color;\n"
                         "void main() {\n"
                         "    frag_color = vec4(1.0, 0.5, 0.2, 1.0);\n"
                         "}\n";

  GLuint vert = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vert, 1, &vert_src, NULL);
  glCompileShader(vert);

  GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(frag, 1, &frag_src, NULL);
  glCompileShader(frag);

  GLuint program = glCreateProgram();
  glAttachShader(program, vert);
  glAttachShader(program, frag);
  glLinkProgram(program);

  glDeleteShader(vert);
  glDeleteShader(frag);

  float vertices[] = {
      // x      y       z
      -0.5f, -0.5f, 0.f, // vértice da esquerda
      0.5f,  -0.5f, 0.f, // vértice da direita
      0.f,   0.5f,  0.f, // vértice do topo
  };

  VBO vbo = vbo_new(GL_STATIC_DRAW);
  VAO vao = vao_new();

  vao_bind(vao);
  vbo_bind(vbo);

  vbo_data(vbo, vertices, sizeof(vertices));
  vao_attrib(vao, 0, 3, GL_FLOAT, sizeof(float) * 3, 0);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    

        glfwSwapBuffers(window);
    glfwPollEvents();
  }

  vao_unbind();
  vbo_unbind();

  vao_free(&vao);
  vbo_free(&vbo);

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
