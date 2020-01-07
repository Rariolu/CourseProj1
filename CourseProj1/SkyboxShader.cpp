#include "SkyboxShader.h"

SkyboxShader::SkyboxShader(string filepath) : AbstractShader(filepath)
{
	GLuint program = GetProgram();

	projection = glGetUniformLocation(program, "projection");
	view = glGetUniformLocation(program, "view");

	skybox = glGetUniformLocation(program, "skybox");

}

void SkyboxShader::Update(Transform* transform, Camera* camera)
{
	Update(camera);
}

void SkyboxShader::Update(Camera* camera)
{
	//Get a view matrix with translation removed to make
	//sure that the skybox follows the camera but rotation
	//is kept so that the view depends on the direction
	//of the camera.
	Matrix viewMat = RemoveTranslation(camera->GetView());
	Matrix projMat = camera->GetProjection();
	//glUniform1i(skybox, 0);
	glUniformMatrix4fv(projection, 1, GLU_FALSE, &projMat[0][0]);
	glUniformMatrix4fv(view, 1, GLU_FALSE, &viewMat[0][0]);

}