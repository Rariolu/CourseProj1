#version 120

attribute vec3 position;
attribute vec2 texCoord;

uniform vec3 mPosition;
uniform vec3 rotation;
uniform vec3 scale;
uniform mat4 viewProjection;

const float PI = 3.1415926535897932384626433832795;

varying vec2 texCoord0;

mat4 RotationMatrix(vec3 axis, float angle)
{
	float PI180 = float(PI / 180.0);
    float s = sin(angle*PI180);
    float c = cos(angle*PI180);
    float oc = 1.0 - c;
    return mat4(oc * axis.x * axis.x + c,           oc * axis.x * axis.y - axis.z * s,  oc * axis.z * axis.x + axis.y * s,  0.0,
                oc * axis.x * axis.y + axis.z * s,  oc * axis.y * axis.y + c,           oc * axis.y * axis.z - axis.x * s,  0.0,
                oc * axis.z * axis.x - axis.y * s,  oc * axis.y * axis.z + axis.x * s,  oc * axis.z * axis.z + c,           0.0,
                0.0,                                0.0,                                0.0,                                1.0);
}

mat4 ScaleMatrix(vec3 scale)
{
	return mat4(scale.x,	0,			0,			0,
				0,			scale.y,	0,			0,
				0,			0,			scale.z,	0,
				0,			0,			0,			1);
}

mat4 TranslationMatrix(vec3 v)
{
	return mat4(1,	0,	0,	v.x,
				0,	1,	0,	v.y,
				0,	0,	1,	v.z,
				0,	0,	0,	1);
}

void main()
{
	mat4 positionMatrix = TranslationMatrix(mPosition);
	mat4 rotX = RotationMatrix(vec3(1,0,0),rotation.x);
	mat4 rotY = RotationMatrix(vec3(0,1,0),rotation.y);
	mat4 rotZ = RotationMatrix(vec3(0,0,1),rotation.z);
	mat4 rotationMatrix = rotX * rotY * rotZ;
	mat4 scaleMatrix = ScaleMatrix(scale);
	mat4 model = positionMatrix * rotationMatrix * scaleMatrix;
	mat4 transform = viewProjection * model;
	gl_Position = transform * vec4(position, 1.0);
	texCoord0 = texCoord;
}