//#version 120

attribute vec4 coord;
varying vec2 texture;

void main()
{
    gl_Position = vec4(coord.xy, 0, 1);
	texture = coord.zw;
}