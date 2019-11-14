#ifndef _ORIGINALSHADER_H
#define _ORIGINALSHADER_H

#include "AbstractShader.h"

class OriginalShader : public AbstractShader
{
	public:
		OriginalShader(string filename);
		void Update(Transform* transform, Camera* camera);
	private:
		GLuint uniforms[1];
};

#endif