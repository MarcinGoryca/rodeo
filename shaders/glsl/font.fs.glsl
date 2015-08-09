//#version 120

varying vec2 texture;
uniform sampler2D tex;
uniform vec4 color;

void main()
{
    gl_FragColor = vec4(1, 1, 1, texture2D(tex, texture).a) * color;
}