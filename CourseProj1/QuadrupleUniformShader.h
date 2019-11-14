#ifndef _TRIPLEUNIFORMSHADER_H
#define _TRIPLEUNIFORMSHADER_H

#include "AbstractShader.h"

class QuadrupleUniformShader : public AbstractShader
{
	public:
		QuadrupleUniformShader(string filename);
		void Update(Transform* transform, Camera* camera);
	private:
		GLuint uniforms[4];
};

#endif