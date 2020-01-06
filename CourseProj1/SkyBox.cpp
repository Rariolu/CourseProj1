#include "SkyBox.h"

SkyBox::SkyBox(string texturePath, string shaderName)
{
	cubeMap = CubeMap(texturePath);
	skyboxShader = (SkyboxShader*)ResourceManager::Instance()->GetShader(shaderName);
}

SkyBox::~SkyBox()
{

}

void SkyBox::Render()
{
	if (camera)
	{
		skyboxShader->Bind();
		//update
		cubeMap.Bind();
		//render mesh
	}
}

void SkyBox::SetCamera(Camera* cam)
{
	camera = cam;
}