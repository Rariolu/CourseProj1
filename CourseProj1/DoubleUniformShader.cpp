#include "DoubleUniformShader.h"

DoubleUniformShader::DoubleUniformShader(string filename) : AbstractShader(filename)
{
	GLuint program = GetProgram();
	glBindAttribLocation(program, 0, "position"); // associate attribute variable with our shader program attribute (in this case attribute vec3 position;)
	glBindAttribLocation(program, 1, "texCoord");
	uniforms[0] = glGetUniformLocation(program, "model");
	uniforms[1] = glGetUniformLocation(program, "viewProjection");
}

void DoubleUniformShader::Update(Transform* transform, Camera* camera)
{
	glUniformMatrix4fv(uniforms[0], 1, GLU_FALSE, &transform->GetModel()[0][0]);
	glUniformMatrix4fv(uniforms[1], 1, GLU_FALSE, &camera->GetViewProjection()[0][0]);
}