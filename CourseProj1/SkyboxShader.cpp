#include "SkyboxShader.h"

SkyboxShader::SkyboxShader(string filepath) : AbstractShader(filepath)
{
	GLuint program = GetProgram();

}

void SkyboxShader::Update(Transform* transform, Camera* camera)
{

}