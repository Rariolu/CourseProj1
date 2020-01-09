#ifndef _SKYBOX_SHADER_H
#define _SKYBOX_SHADER_H

#include "AbstractShader.h"

//A shader class used to render skyboxes.
class SkyboxShader : public AbstractShader
{
	public:
		//Load a vertex and fragment shader
		//from the given file path.
		SkyboxShader(string filepath);

		//Necessary implementation of "Update" method
		//in order for instances of this class to be made.
		void Update(Transform* transform, Camera* camera);

		//Update the shader's uniform values according to the
		//camera's perspective.
		void Update(Camera* camera);
	private:
		//The address of the "projection" uniform variable.
		GLuint projection;

		//The address of the "skybox" uniform variable.
		GLuint skybox;

		//The address of the "view" uniform variable.
		GLuint view;
};

#endif