#ifndef _SKYBOX_H
#define _SKYBOX_H

#include "Camera.h"
#include "CubeMap.h"

class SkyBox
{
	public:
		SkyBox(string texturePath);
		~SkyBox();
		void Render();
		void SetCamera(Camera* cam);
	private:
		Camera * camera;
		CubeMap cubeMap = nullptr;
};

#endif