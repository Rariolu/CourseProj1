#include "SkyboxShader.h"

SkyboxShader::SkyboxShader(string filepath) : AbstractShader(filepath)
{
	GLuint program = GetProgram();

	view = glGetUniformLocation(program, "view");
	projection = glGetUniformLocation(program, "projection");
}

void SkyboxShader::Update(Transform* transform, Camera* camera)
{
	Update(camera);
}

void SkyboxShader::Update(Camera* camera)
{
	Matrix viewMat = Matrix(Mat3(camera->GetView()));
	Matrix projMat = camera->GetProjection();
	glUniformMatrix4fv(view, 1, GLU_FALSE, &viewMat[0][0]);
	glUniformMatrix4fv(projection, 1, GLU_FALSE, &projMat[0][0]);
}