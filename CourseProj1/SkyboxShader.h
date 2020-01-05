#ifndef _SKYBOX_SHADER_H
#define _SKYBOX_SHADER_H

#include "AbstractShader.h"

class SkyboxShader : public AbstractShader
{
	public:
		SkyboxShader(string filepath);
		void Update(Transform* transform, Camera* camera);
	private:
		GLuint projection;
		GLuint view;
};

#endif