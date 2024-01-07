#version 330 core

layout (location = 0) in vec3 aPos;
out vec4 color;

void main()
{
   gl_Position = vec4(aPos, 1.0);
   color = vec4(0.2, 0.4, 0.8, 1.0);
}