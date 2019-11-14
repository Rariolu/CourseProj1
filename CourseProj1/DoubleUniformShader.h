#ifndef _DOUBLEUNIFORMSHADER_H
#define _DOUBLEUNIFORMSHADER_H

#include "AbstractShader.h"

class DoubleUniformShader : public AbstractShader
{
	public:
		DoubleUniformShader(string filename);
		void Update(Transform* transform, Camera* camera);
	private:
		GLuint uniforms[2];
};

#endif