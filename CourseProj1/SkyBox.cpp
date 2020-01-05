#include "SkyBox.h"

SkyBox::SkyBox(string texturePath)
{
	cubeMap = CubeMap(texturePath);
}

SkyBox::~SkyBox()
{

}

void SkyBox::Render()
{
	if (camera)
	{

	}
}

void SkyBox::SetCamera(Camera* cam)
{
	camera = cam;
}