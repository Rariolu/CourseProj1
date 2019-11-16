#include "OriginalShader.h"

OriginalShader::OriginalShader(string filename) : AbstractShader(filename)
{
	GLuint program = GetProgram();

	glBindAttribLocation(program, 0, "position");
	glBindAttribLocation(program, 1, "texCoord");

	uniform = glGetUniformLocation(program, "mvp");
}

void OriginalShader::Update(Transform* transform, Camera* camera)
{
	Matrix mvp = camera->GetViewProjection() * transform->GetModel();
	glUniformMatrix4fv(uniform, 1, GLU_FALSE, &mvp[0][0]);
}