#include "OriginalShader.h"

OriginalShader::OriginalShader(string filename) : AbstractShader(filename)
{
	GLuint program = GetProgram();
	glBindAttribLocation(program, 0, "position"); // associate attribute variable with our shader program attribute (in this case attribute vec3 position;)
	glBindAttribLocation(program, 1, "texCoord");

	uniforms[0] = glGetUniformLocation(program, "transform");
}

void OriginalShader::Update(Transform* transform, Camera* camera)
{
	Matrix mvp = camera->GetViewProjection() * transform->GetModel();
	glUniformMatrix4fv(uniforms[0], 1, GLU_FALSE, &mvp[0][0]);
}