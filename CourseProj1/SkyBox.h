#ifndef _SKYBOX_H
#define _SKYBOX_H

#include "CubeMap.h"
#include "SkyboxShader.h"
#include "ResourceManager.h"

class SkyBox
{
	public:
		SkyBox(string texturePath, string shaderName);
		~SkyBox();
		void Render();
		void SetCamera(Camera* cam);
	private:
		Camera * camera;
		CubeMap cubeMap = nullptr;
		SkyboxShader* skyboxShader;
};

#endif