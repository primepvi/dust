#version 330 core

in vec4 v_color;
in vec2 v_texCoords;

out vec4 frag_color;
uniform sampler2D u_sprite;

void main() {
  frag_color = texture(u_sprite, v_texCoords) * v_color;  
}
