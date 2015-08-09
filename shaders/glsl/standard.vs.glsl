#version 330 core
attribute vec3 coord;

out vec3 out_color;
in vec3 in_color;

uniform mat4 projection;
uniform mat4 modelview;

void main()
{
  out_color = in_color;

  gl_Position = projection * vec4(coord, 1.0);
}
