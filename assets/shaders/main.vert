#version 330 core
layout(location=0) in vec2 a_pos;
layout(location=1) in vec2 a_texCoords;

out vec4 v_color;
out vec2 v_texCoords;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_proj;

void main() {
  v_color = vec4(1.0, 1.0, 1.0, 1.0);
  v_texCoords = a_texCoords;

  gl_Position = u_proj * u_view * u_model * vec4(a_pos, 0.0, 1.0);
}
