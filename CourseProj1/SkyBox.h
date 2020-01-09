#ifndef _SKYBOX_H
#define _SKYBOX_H

#include "CubeMap.h"
#include "SkyboxShader.h"
#include "ResourceManager.h"

class SkyBox
{
	public:
		//Creates a skybox by using the given file path
		//to derive 6 source textures and a given name
		//for the appropriate shader
		SkyBox(string texturePath, string shaderName);
		~SkyBox();

		//Render the Skybox in order for it to be seen
		void Render();

		//Set the camera that's used to 
		void SetCamera(Camera* cam);
	private:

		//Generate and bind the skybox vertices and generate
		//the required buffer.
		void InitialiseCube();

		//The camera that's being currently used.
		Camera * camera;

		//The cubemap texture to render onto the skybox.
		CubeMap cubeMap;

		//The shader used to render the skybox.
		SkyboxShader* skyboxShader;

		//The skybox's vertex array object.
		unsigned int skyboxVAO;

		//The skybox's vertex buffer object.
		unsigned int skyboxVBO;
		
		//The points used to create the skybox (the positions
		//of a generic cube).
		const float skyboxVertices[108] =
		{
			-1.0f,  1.0f, -1.0f,
			-1.0f, -1.0f, -1.0f,
			 1.0f, -1.0f, -1.0f,
			 1.0f, -1.0f, -1.0f,
			 1.0f,  1.0f, -1.0f,
			-1.0f,  1.0f, -1.0f,

			-1.0f, -1.0f,  1.0f,
			-1.0f, -1.0f, -1.0f,
			-1.0f,  1.0f, -1.0f,
			-1.0f,  1.0f, -1.0f,
			-1.0f,  1.0f,  1.0f,
			-1.0f, -1.0f,  1.0f,

			 1.0f, -1.0f, -1.0f,
			 1.0f, -1.0f,  1.0f,
			 1.0f,  1.0f,  1.0f,
			 1.0f,  1.0f,  1.0f,
			 1.0f,  1.0f, -1.0f,
			 1.0f, -1.0f, -1.0f,

			-1.0f, -1.0f,  1.0f,
			-1.0f,  1.0f,  1.0f,
			 1.0f,  1.0f,  1.0f,
			 1.0f,  1.0f,  1.0f,
			 1.0f, -1.0f,  1.0f,
			-1.0f, -1.0f,  1.0f,

			-1.0f,  1.0f, -1.0f,
			 1.0f,  1.0f, -1.0f,
			 1.0f,  1.0f,  1.0f,
			 1.0f,  1.0f,  1.0f,
			-1.0f,  1.0f,  1.0f,
			-1.0f,  1.0f, -1.0f,

			-1.0f, -1.0f, -1.0f,
			-1.0f, -1.0f,  1.0f,
			 1.0f, -1.0f, -1.0f,
			 1.0f, -1.0f, -1.0f,
			-1.0f, -1.0f,  1.0f,
			 1.0f, -1.0f,  1.0f
		};
};

#endif