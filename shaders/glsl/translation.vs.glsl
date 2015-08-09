#version 330 core

uniform mat4 projection_matrix;
uniform mat4 model_matrix;

in vec4 position;
in vec4 color;

out vec4 vsfs_color;

void main()
{
    vsfs_color = color;
    gl_Position = projection_matrix * position;
}