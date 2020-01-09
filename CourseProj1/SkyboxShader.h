#ifndef _SKYBOX_SHADER_H
#define _SKYBOX_SHADER_H

#include "AbstractShader.h"

class SkyboxShader : public AbstractShader
{
	public:
		SkyboxShader(string filepath);
		void Update(Transform* transform, Camera* camera);
		void Update(Camera* camera);
	private:
		GLuint projection;
		GLuint skybox;
		GLuint view;
};

#endif