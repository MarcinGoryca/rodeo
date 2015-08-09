#version 330 core

in vec4 vsfs_color;

out vec4 color;

void main()
{
    color = vsfs_color;
}