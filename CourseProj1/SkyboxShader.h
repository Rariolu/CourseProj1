#ifndef _SKYBOX_SHADER_H
#define _SKYBOX_SHADER_H

#include "AbstractShader.h"

class SkyboxShader : public AbstractShader
{
	public:
		SkyboxShader(string filepath);
};

#endif