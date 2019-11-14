#version 120

attribute vec3 position;
attribute vec2 texCoord;

varying vec2 texCoord0;
varying mat4 transform;

uniform mat4 model;
uniform mat4 viewProjection;

void main()
{
	transform = viewProjection * model;
	gl_Position = transform * vec4(position, 1.0);
	texCoord0 = texCoord;
}